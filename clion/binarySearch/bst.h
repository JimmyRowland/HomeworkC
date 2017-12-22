#pragma once
#include <string>
#include <stdexcept>
//
// bst - binary search tree without iterators
// CS-20A: Data Structures With C++
// Professor Scott E Robertson
// 3/24/2017
//
using namespace std;
namespace cs20a
{
	template <typename T> class bst;

	template <typename T>
	class bst_node {
		friend class bst<T>;

	private:
		T value;
		bst_node<T> *left, *right, *parent;

		bst_node() : value(), left(nullptr), right(nullptr), parent(nullptr) {}
		bst_node(const T& t, bst_node<T> *left = nullptr, bst_node<T> *right = nullptr, bst_node<T> *parent = nullptr)
			: value(t), left(left), right(right), parent(parent) {};

	};

	template <typename T>
	class bst {
	public:
		bst();
		bst(const bst<T> &rhs);
		~bst();

		bst<T>& operator =(const bst<T> & rhs);

		bool empty() const;
		void clear();
		size_t size() const;

		void insert(const T & value);
		void remove(const T & value);

		bool contains(const T & value) const;
		T & retrieve(T & value) const;

		void print();
				
		//*** Implement these functions 
		void inOrder(void(*func)(const T &) = nullptr) const;
		void preOrder(void(*func)(const T &) = nullptr) const;
		void postOrder(void(*func)(const T &) = nullptr) const;
		//***

	private:
		bst_node<T> *root;
		size_t _size;

		void init();
		void makeEmpty(bst_node<T>* node);
		void copy(const bst_node<T>* node);

		void insert(const T &  value, bst_node<T>* node);
		void remove(const T &  value, bst_node<T>* node);

		bool contains(const T&  value, bst_node<T>* node) const;
		T & retrieve(T & value, bst_node<T>* node) const;

		void print(bst_node<T>* node, size_t level) const;

		//*** Implement these functions 
		void inOrder(void(*func)(const T &), bst_node<T>* node) const;
		void preOrder(void(*func)(const T &), bst_node<T>* node) const;
		void postOrder(void(*func)(const T &), bst_node<T>* node) const;
		//***

		bst_node<T> * findNode(const T &) const;
		bst_node<T> * findNode(const T &, bst_node<T>* node) const;
		bst_node<T> * findParentNode(bst_node<T>* node) const;
		bst_node<T> * findParentNode(bst_node<T>* node, bst_node<T>* child, bst_node<T>* parent) const;

		bst_node<T> * getMaxNode(bst_node<T>* node) const;
		bst_node<T> * getMinNode(bst_node<T>* node) const;
	};

	template <typename T>
	bst<T>::bst() {
		init();
	}

	template <typename T>
	bst<T>::bst(const bst<T> &rhs) {
		init();
		copy(rhs.root);
	}

	template<class T>
	bst<T>& bst<T>::operator=(const bst<T>& rhs) {
		if (this != &rhs) {
			clear();
			copy(rhs.root);
		}
		return *this;
	}

	template <typename T>
	bst<T>::~bst() {
		makeEmpty(root);
	}

	template<typename T>
	bool bst<T>::empty() const {
		return root == nullptr;
	}

	template<typename T>
	void bst<T>::clear() {
		makeEmpty(root);
		init();
	}

	template<typename T>
	size_t bst<T>::size() const {
		return _size;
	}

	template<class T>
	void bst<T>::copy(const bst_node<T>* node) {
		if (node != NULL)
			insert(node->value);

		if (node->left != NULL)
			copy(node->left);

		if (node->right != NULL)
			copy(node->right);
	}

	template<class T>
	void bst<T>::makeEmpty(bst_node<T>* node) {
		if (node != NULL) {
			if (node->left != NULL)
				makeEmpty(node->left);

			if (node->right != NULL)
				makeEmpty(node->right);

			delete node;
			node = NULL;

			_size--;
		}
	}

	template<class T>
	void bst<T>::init() {
		root = nullptr;
		_size = 0;
	}

	template<class T>
	void bst<T>::insert(const T &value) {
		if (root == nullptr)
		{
			root = new bst_node<T>(value, nullptr, nullptr, nullptr);
			_size++;
		}
		else
		{
			insert(value, root);
		}
	}

	template<class T>
	void bst<T>::insert(const T &value, bst_node<T>* node) {
		if (value < node->value)
		{
			if (node->left == nullptr)
			{
				node->left = new bst_node<T>(value, nullptr, nullptr, node);
				_size++;
			}
			else
			{
				insert(value, node->left);
			}
		}
		else
			if (value > node->value)
			{
				if (node->right == nullptr)
				{
					node->right = new bst_node<T>(value, nullptr, nullptr, node);
					_size++;
				}
				else
				{
					insert(value, node->right);
				}
			}
	}

	template<class T>
	void bst<T>::remove(const T &value) {
		if (root != nullptr)

			remove(value, root);

	}

	template<class T>
	void bst<T>::remove(const T &value, bst_node<T>* node) {
		bst_node<T>* current = findNode(value, node);

		if (current == nullptr)
			return;

		bst_node<T>* parent = findParentNode(current);

		// Case 1: node to be deleted has no children 
		if (current->left == nullptr && current->right == nullptr)
		{
			if (parent != nullptr)
			{
				if (current->value < parent->value)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}

			delete current;
			_size--;
		}
		// Case 2: node to be deleted has one child
		else if (current->left != nullptr && current->right == nullptr)
		{
			if (parent != nullptr)
			{
				current->left->parent = parent;
				if (current->value < parent->value)
					parent->left = current->left;
				else
					parent->right = current->left;
			}

			delete current;
			_size--;
		}
		else if (current->left == nullptr && current->right != nullptr)
		{
			if (parent != nullptr)
			{
				current->right->parent = parent;
				if (current->value < parent->value)
					parent->left = current->right;
				else
					parent->right = current->right;
			}

			delete current;
			_size--;
		}
		// Case 3: node to be deleted has two children
		else if (current->left != nullptr && current->right != nullptr)
		{
			bst_node<T>*  maxNode = getMaxNode(current->left);
			bst_node<T>*  maxParentNode = findParentNode(maxNode);

			current->value = maxNode->value;

			// Delete maxNode: right pointer is nullptr 
			if (maxParentNode != nullptr)
			{
				if (maxNode->left != nullptr)
					maxNode->left->parent = maxParentNode;

				if (maxNode->value < maxParentNode->value)
					maxParentNode->left = maxNode->left;
				else
					maxParentNode->right = maxNode->left;
			}

			delete maxNode;
			_size--;
		}
		else
		{
			return;
		}
	}

	template<class T>
	bst_node<T> * bst<T>::findNode(const T &value) const {
		return findNode(value, root);
	}

	template<class T>
	bst_node<T> *  bst<T>::findNode(const T &value, bst_node<T>* node) const {
		if (node == nullptr)
			return nullptr;
		else if (value < node->value)
			return findNode(value, node->left);
		else if (value > node->value)
			return findNode(value, node->right);
		else // value == node->value
			return node;
	}

	template<class T>
	bst_node<T> * bst<T>::findParentNode(bst_node<T>* node) const {
		bst_node<T> *parent = nullptr;
		bst_node<T> *child = root;
		return findParentNode(node, child, parent);
	}

	template<class T>
	bst_node<T> * bst<T>::findParentNode(bst_node<T>* node, bst_node<T>* child, bst_node<T>* parent) const {
		if (child == nullptr)
			return nullptr;
		else if (node->value < child->value)
		{
			parent = child;
			return findParentNode(node, child->left, parent);
		}
		else if (node->value > child->value)
		{
			parent = child;
			return findParentNode(node, child->right, parent);
		}
		else // child == node
			return parent;
	}

	template<class T>
	T & bst<T>::retrieve(T &value) const {
		return retrieve(value, root);
	}

	template<class T>
	T & bst<T>::retrieve(T &value, bst_node<T>* node) const {
		if (node == nullptr)
			throw std::logic_error("Node does not exist.");
		else if (value < node->value)
			return retrieve(value, node->left);
		else if (value > node->value)
			return retrieve(value, node->right);
		else
			return node->value;
	}

	template<typename T>
	void bst<T>::print()
	{
		size_t indent = 0;
		print(root, indent);
	}

	template<typename T>
	void bst<T>::print(bst_node<T>* node, size_t level) const
	{
		if (node != nullptr)
		{
			print(node->left, level + 1);
			cout << std::string(level * 4, '-') << node->value << endl;
			print(node->right, level + 1);
		}
	}

	template<class T>
	bool bst<T>::contains(const T &value) const {
		if (root == nullptr)
			return false;
		else
			return contains(value, root);
	}

	template<class T>
	bool bst<T>::contains(const T &value, bst_node<T> *node) const {
		if (node == nullptr)
			return false;
		else if (value < node->value)
			return contains(value, node->left);
		else if (value > node->value)
			return contains(value, node->right);
		else // value == node->value
			return true;
	}

	template<class T>
	void bst<T>::inOrder(void(*func)(const T &)) const {
		if(!empty()) inOrder(func,root);

	}

	template<class T>
	void bst<T>::inOrder(void(*func)(const T &), bst_node<T>* node) const {
		if (node->left) inOrder(func,node->left);
		func(node->value);
		if(node->right) inOrder(func,node->right);
	}

	template<class T>
	void bst<T>::preOrder(void(*func)(const T &)) const {
		if(!empty()) preOrder(func,root);
	}

	template<class T>
	void bst<T>::preOrder(void(*func)(const T &), bst_node<T>* node) const {

		func(node->value);
		if(node->left) preOrder(func,node->left);
		if(node->right) preOrder(func,node->right);

	}

	template<class T>
	void bst<T>::postOrder(void(*func)(const T &)) const {
		if(!empty()) postOrder(func,root);
	}

	template<class T>
	void bst<T>::postOrder(void(*func)(const T &), bst_node<T>* node) const {

		if(node->left) postOrder(func,node->left);
		if(node->right) postOrder(func,node->right);
		func(node->value);
	}

	template<class T>
	bst_node<T> * bst<T>::getMaxNode(bst_node<T>* node) const {
		if (node == nullptr)
			return node;
		if (node->right != nullptr)
			return getMaxNode(node->right);
		else
			return node;
	}

	template<class T>
	bst_node<T> * bst<T>::getMinNode(bst_node<T>* node) const {
		if (node == nullptr)
			return node;
		if (node->left != nullptr)
			return getMinNode(node->left);
		else
			return node;
	}
}