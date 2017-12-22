#pragma once
//#include <stdexcept>
//
// bst - binary search tree with iterators
// CS-20A: Data Structures With C++
// Professor Scott E Robertson
// 3/24/2017
//
namespace cs20a {
	template <typename T> class bst;
	template <typename T> class bst_iterator;
	template <typename T> class const_bst_iterator;

	template <typename T>
	class bst_node {
		friend class bst<T>;
		friend class bst_iterator<T>;
		friend class const_bst_iterator<T>;

	private:
		T value;
		bst_node<T> *left, *right, *parent;

		bst_node() : value(), left(nullptr), right(nullptr), parent(nullptr) {}
		bst_node(const T& t, bst_node<T> *left = nullptr, bst_node<T> *right = nullptr, bst_node<T> *parent = nullptr)
			: value(t), left(left), right(right), parent(parent) {};

	};

	template <typename T>
	class bst_iterator {
		friend class bst<T>;
		friend class bst_node<T>;

	public:
		T& operator*() const { return np->value; };
		bool operator == (const bst_iterator<T>& li) const { return np == li.np; };
		bool operator!=(const bst_iterator<T>& li) const { return np != li.np; };

		const bst_iterator<T>& operator++();
		const bst_iterator<T> operator++(int);

	private:
		bst<T> *tree;
		bst_node<T> *np;

		bst_iterator(bst_node<T> *p, bst<T> *t) : tree(t), np(p) {}

	};

	template<typename T>
	const bst_iterator<T> & bst_iterator<T>::operator ++ () { // Pre-increment	
		bst_node<T> *p;

		if (np == nullptr)
		{
			// ++ from end(). get the root of the tree
			np = tree->root;

			// error! ++ requested for an empty tree
			if (np == nullptr)
				throw std::logic_error("stree iterator operator++ (): tree empty");

			// move to the smallest value in the tree,
			// which is the first node inorder
			while (np->left != nullptr) {
				np = np->left;
			}
		}
		else
			if (np->right != nullptr)
			{
				// successor is the furthest left node of
				// right subtree
				np = np->right;

				while (np->left != nullptr) {
					np = np->left;
				}
			}
			else
			{
				// have already processed the left subtree, and
				// there is no right subtree. move up the tree,
				// looking for a parent for which m_ptr is a left child,
				// stopping if the parent becomes nullptr. a non-nullptr parent
				// is the successor. if parent is nullptr, the original node
				// was the last node inorder, and its successor
				// is the end of the list
				p = np->parent;
				while (p != nullptr && np == p->right)
				{
					np = p;
					p = p->parent;
				}

				// if we were previously at the right-most node in
				// the tree, m_ptr = nullptr, and the iterator specifies
				// the end of the list
				np = p;
			}

		return *this;
	}

	template<class T>
	const bst_iterator<T>  bst_iterator<T>::operator ++ (int) { // Post-increment	
		bst_iterator<T> tmp(*this);
		bst_node<T> *p;

		if (np == nullptr)
		{
			// ++ from end(). get the root of the tree
			np = tree->root;

			// error! ++ requested for an empty tree
			if (np == nullptr)
				throw std::logic_error("stree iterator operator++ (): tree empty");

			// move to the smallest value in the tree,
			// which is the first node inorder
			while (np->left != nullptr) {
				np = np->left;
			}
		}
		else
			if (np->right != nullptr)
			{
				// successor is the furthest left node of
				// right subtree
				np = np->right;

				while (np->left != nullptr) {
					np = np->left;
				}
			}
			else
			{
				// have already processed the left subtree, and
				// there is no right subtree. move up the tree,
				// looking for a parent for which m_ptr is a left child,
				// stopping if the parent becomes nullptr. a non-nullptr parent
				// is the successor. if parent is nullptr, the original node
				// was the last node inorder, and its successor
				// is the end of the list
				p = np->parent;
				while (p != nullptr && np == p->right)
				{
					np = p;
					p = p->parent;
				}

				// if we were previously at the right-most node in
				// the tree, m_ptr = nullptr, and the iterator specifies
				// the end of the list
				np = p;
			}

		return tmp;
	}

	template <typename T>
	class const_bst_iterator {
		friend class bst<T>;

	public:
		T const& operator*() const { return np->value; };
		bool operator == (const const_bst_iterator<T>& li) const { return np == li.np; };
		bool operator!=(const const_bst_iterator<T>& li) const { return np != li.np; };

		const const_bst_iterator<T>& operator++();
		const const_bst_iterator<T> operator++(int);

	private:
		const bst<T>  *tree;
		const bst_node<T> *np;

		const_bst_iterator(const bst_node<T> *p, const bst<T> *t) : tree(t), np(p) {}

	};

	template<typename T>
	const const_bst_iterator<T> & const_bst_iterator<T>::operator ++ () { // Pre-increment	
		bst_node<T> *p;

		if (np == nullptr)
		{
			// ++ from end(). get the root of the tree
			np = tree->root;

			// error! ++ requested for an empty tree
			if (np == nullptr)
				throw std::logic_error("stree iterator operator++ (): tree empty");

			// move to the smallest value in the tree,
			// which is the first node inorder
			while (np->left != nullptr) {
				np = np->left;
			}
		}
		else
			if (np->right != nullptr)
			{
				// successor is the furthest left node of
				// right subtree
				np = np->right;

				while (np->left != nullptr) {
					np = np->left;
				}
			}
			else
			{
				// have already processed the left subtree, and
				// there is no right subtree. move up the tree,
				// looking for a parent for which m_ptr is a left child,
				// stopping if the parent becomes nullptr. a non-nullptr parent
				// is the successor. if parent is nullptr, the original node
				// was the last node inorder, and its successor
				// is the end of the list
				p = np->parent;
				while (p != nullptr && np == p->right)
				{
					np = p;
					p = p->parent;
				}

				// if we were previously at the right-most node in
				// the tree, m_ptr = nullptr, and the iterator specifies
				// the end of the list
				np = p;
			}

		return *this;
	}

	template<class T>
	const const_bst_iterator<T>  const_bst_iterator<T>::operator ++ (int) { // Post-increment	
		const_bst_iterator<T> tmp(*this);
		bst_node<T> *p;

		if (np == nullptr)
		{
			// ++ from end(). get the root of the tree
			np = tree->root;

			// error! ++ requested for an empty tree
			if (np == nullptr)
				throw std::logic_error("stree iterator operator++ (): tree empty");

			// move to the smallest value in the tree,
			// which is the first node inorder
			while (np->left != nullptr) {
				np = np->left;
			}
		}
		else
			if (np->right != nullptr)
			{
				// successor is the furthest left node of
				// right subtree
				np = np->right;

				while (np->left != nullptr) {
					np = np->left;
				}
			}
			else
			{
				// have already processed the left subtree, and
				// there is no right subtree. move up the tree,
				// looking for a parent for which m_ptr is a left child,
				// stopping if the parent becomes nullptr. a non-nullptr parent
				// is the successor. if parent is nullptr, the original node
				// was the last node inorder, and its successor
				// is the end of the list
				p = np->parent;
				while (p != nullptr && np == p->right)
				{
					np = p;
					p = p->parent;
				}

				// if we were previously at the right-most node in
				// the tree, m_ptr = nullptr, and the iterator specifies
				// the end of the list
				np = p;
			}

		return tmp;
	}

	template <typename T>
	class bst {
		friend class bst_iterator<T>;
		friend class const_bst_iterator<T>;

	public:
		typedef bst_iterator<T> iterator;
		typedef const_bst_iterator<T> const_iterator;

	public:
		bst();
		bst(const bst<T> &rhs);
		~bst();

		bst<T>& operator =(const bst<T> & rhs);

		bool operator==(const bst<T> &rhs) const;
		bool operator!=(const bst<T> &rhs) const;

		bool empty() const;
		void clear();
		size_t size() const;

		void insert(const T & value);
		void update(const T & value);
		void remove(const T & value);

		bool contains(const T & value) const;
		T & retrieve(T & value) const;

		void inOrder(void(*func)(const T &)) const;
		void preOrder(void(*func)(const T &)) const;
		void postOrder(void(*func)(const T &)) const;

		iterator begin();
		iterator end();
		const_iterator cbegin() const;
		const_iterator cend() const;

	private:
		bst_node<T> *root;
		size_t _size;

		void init();
		void makeEmpty(bst_node<T>* node);
		void copy(const bst_node<T>* node);

		void insert(const T &  value, bst_node<T>* node);
		void update(const T &  value, bst_node<T>* node);
		void remove(const T &  value, bst_node<T>* node);

		bool contains(const T&  value, bst_node<T>* node) const;
		T & retrieve(T & value, bst_node<T>* node) const;

		void inOrder(void(*func)(const T &), bst_node<T>* node) const;
		void preOrder(void(*func)(const T &), bst_node<T>* node) const;
		void postOrder(void(*func)(const T &), bst_node<T>* node) const;

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
		makeEmpty();
		init();
	}

	template<typename T>
	size_t bst<T>::size() const {
		return _size;
	}

	template<typename T>
	bool bst<T>::operator==(const bst<T>& rhs) const {
		if (this == &rhs)
			return true;

		if (size() != rhs.size())
			return false;

		for (bst<T>::const_iterator it1 = cbegin(), it2 = rhs.cbegin(); it1 != cend(), it2 != rhs.cend(); it1++, it2++)
			if (*it1 != *it2)
				return false;

		return true;
	}

	template<typename T>
	bool bst<T>::operator!=(const bst<T>& rhs) const {
		return !(*this == rhs);
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
		else if (value > node->value)
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
		else
		{
			throw std::logic_error("Node already exists.");
		}
	}

	template<class T>
	void bst<T>::update(const T &value) {
		if (root != nullptr)
			return update(value, root);
	}

	template<class T>
	void bst<T>::update(const T &value, bst_node<T>* node) {
		if (node == nullptr)
			throw std::logic_error("Node does not exist.");
		else if (value < node->value)
			update(value, node->left);
		else if (value > node->value)
			update(value, node->right);
		else
			node->value = value;
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
		inOrder(func, root);
	}

	template<class T>
	void bst<T>::inOrder(void(*func)(const T &), bst_node<T>* node) const {
		if (node != nullptr)
		{
			inOrder(func, node->left);
			if (func != nullptr)
				func(node->value);
			inOrder(func, node->right);
		}
	}

	template<class T>
	void bst<T>::preOrder(void(*func)(const T &)) const {
		preOrder(func, root);
	}

	template<class T>
	void bst<T>::preOrder(void(*func)(const T &), bst_node<T>* node) const {
		if (node != nullptr)
		{
			if (func != nullptr)
				func(node->value);
			preOrder(func, node->left);
			preOrder(func, node->right);
		}
	}

	template<class T>
	void bst<T>::postOrder(void(*func)(const T &)) const {
		postOrder(func, root);
	}

	template<class T>
	void bst<T>::postOrder(void(*func)(const T &), bst_node<T>* node) const {
		if (node != nullptr)
		{
			postOrder(func, node->left);
			postOrder(func, node->right);
			if (func != nullptr)
				func(node->value);
		}
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

	template<class T>
	bst_iterator<T> bst<T>::begin() {
		bst_node<T> *current = root;

		if (current != NULL)
			while (current->left != NULL)
				current = current->left;

		return bst_iterator<T>(current, this);
	}

	template<class T>
	bst_iterator<T> bst<T>::end() {
		return bst_iterator<T>(nullptr, this);
	}

	template<class T>
	const_bst_iterator<T> bst<T>::cbegin() const {
		bst_node<T> *current = root;

		if (current != NULL)
			while (current->left != NULL)
				current = current->left;

		return const_bst_iterator<T>(current, this);
	}

	template<class T>
	const_bst_iterator<T> bst<T>::cend() const {
		return const_bst_iterator<T>(nullptr, this);
	};

}

//iterator insert(iterator position, const T& element) {
//	bst_node<T> * successor = position.np;
//	bst_node<T> * target = new bst_node<T>(element, successor->prev, successor);

//	if (successor->prev != nullptr)
//		successor->prev->next = target;

//	successor->prev = target;

//	if (head->next == successor)
//		head->next = target;

//	_size++;

//	return iterator(target);
//}
//iterator erase(iterator position) {
//	bst_node<T> * successor = position.np->next;
//	bst_node<T> * target = position.np;

//	killNode(target);

//	return iterator(successor);
//}

