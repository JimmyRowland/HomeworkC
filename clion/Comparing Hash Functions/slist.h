//
// slist - singly-linked list with iterators
// CS-20A: Data Structures With C++
// Professor Scott E Robertson
// 3/24/2017
//
#pragma once
#include <stdexcept>
namespace cs20a
{
	template <typename T> class slist;
	template <typename T> class slist_iterator;
	template <typename T> class const_slist_iterator;
	template <typename T> class slist_node;

	template <typename T>
	class slist_node {
		friend class slist<T>;
		friend class slist_iterator<T>;
		friend class const_slist_iterator<T>;

	private:
		slist_node() {};
		slist_node(const T& t, slist_node<T> *next = nullptr) : value(t), next(next) {};

		T value;
		slist_node<T> *next;
	};

	template <typename T>
	class slist_iterator {
		friend class slist<T>;

	public:
		T& operator*() const { return np->value; };
		bool operator == (const slist_iterator<T>& li) const { return np == other.np; };
		bool operator!=(const slist_iterator<T>& li) const { return np != li.np; };

		const slist_iterator<T>& operator++() {
			np = np->next;
			return *this;
		};

		const slist_iterator<T> operator++(int) {
			slist_iterator<T> clone(*this);
			np = np->next;
			return clone;
		};

	private:
		slist_node<T> *np;
		slist_iterator(slist_node<T> *np) : np(np) {};
	};

	template <typename T>
	class const_slist_iterator {
		friend class slist<T>;

	public:
		T const& operator*() const { return np->value; };
		bool operator == (const const_slist_iterator<T>& li) const { return np == other.np; };
		bool operator!=(const const_slist_iterator<T>& li) const { return np != li.np; };

		const const_slist_iterator<T>& operator++() {
			np = np->next;
			return *this;
		};

		const const_slist_iterator<T> operator++(int) {
			const_slist_iterator<T> clone(*this);
			np = np->next;
			return clone;
		};

	private:
		const slist_node<T> *np;
		const_slist_iterator(const slist_node<T> *ptr) : np(ptr) {};
	};

	template <typename T>
	class slist {
	public:
		typedef slist_iterator<T> iterator;
		typedef const_slist_iterator<T> const_iterator;

	public:
		slist();
		slist(const slist<T> &rhs);
		~slist();

		slist<T>& operator =(const slist<T> & rhs);

		bool operator==(const slist<T> & rhs) const;
		bool operator!=(const slist<T> & rhs) const;

		void push_back(const T& element);
		T  pop_back();

		void push_front(const T& element);
		T  pop_front();

		T& front();
		const T& front() const;

		T& back();
		const T& back() const;

		bool empty() const;
		bool full() const;
		void clear();
		size_t size() const;

		void remove(const T& element);
		bool contains(const T& element) const;

		iterator begin() { return slist_iterator<T>(head->next); }
		iterator end() { return slist_iterator<T>(nullptr); }
		const_iterator cbegin() const { return const_slist_iterator<T>(head->next); };
		const_iterator cend() const { return const_slist_iterator<T>(nullptr); };

		iterator insert(iterator position, const T& element) {
			slist_node<T> * successor = position.np;
			slist_node<T> * target = new slist_node<T>(element, successor);

			if (head->next == successor)
				head->next = target;

			_size++;

			return iterator(target);
		}
		iterator erase(iterator position) {
			slist_node<T> * successor = position.np->next;
			slist_node<T> * target = position.np;

			killNode(target);

			return iterator(successor);
		}

	private:
		slist_node<T> header, *head, *tail;
		size_t _size;

		void makeEmpty();
		void init();

		void copy(const slist<T>& rhs);
		void killNode(slist_node<T> *target);
		slist_node<T> *  findNode(const T& element) const;
		slist_node<T> *  findNodePrevious(slist_node<T> * node) const;

	};

	template <typename T>
	slist<T>::slist() {
		init();
	}

	template <typename T>
	slist<T>::slist(const slist<T> &rhs) {
		init();
		copy(rhs);
	}

	template<typename T>
	slist<T> & slist<T>::operator=(const slist<T>& rhs) {
		if (this != &rhs) {
			clear();
			copy(rhs);
		}
		return *this;
	}

	template <typename T>
	slist<T>::~slist() {
		makeEmpty();
	}

	template <typename T>
	void slist<T>::push_back(const T& element) {
		slist_node<T> *  node = new slist_node<T>(element, nullptr);

		if (empty())
			head->next = node;
		else
			tail->next = node;

		tail = node;
		_size++;
	}

	template<typename T>
	T slist<T>::pop_back() {
		if (empty())
			throw std::logic_error("Empty list.");

		T element = tail->value;
		killNode(tail);

		return element;
	}

	template<typename T>
	void slist<T>::push_front(const T & element) {
		slist_node<T> *  node = new slist_node<T>(element, head->next);

		if (empty())
			tail = node;

		head->next = node;

		_size++;
	}

	template<typename T>
	T slist<T>::pop_front() {
		if (empty())
			throw std::logic_error("Empty list.");

		T element = head->next->value;
		killNode(head->next);

		return element;
	}

	template<typename T>
	T& slist<T>::front() {
		return head->next->value;
	}

	template<typename T>
	const T & slist<T>::front() const {
		return head->next->value;
	}

	template<typename T>
	T& slist<T>::back() {
		return tail->value;
	}

	template<typename T>
	const T & slist<T>::back() const {
		return tail->value;
	}

	template<typename T>
	bool slist<T>::empty() const {
		return head->next == nullptr;
	}

	template<typename T>
	bool slist<T>::full() const {
		return false;
	}

	template<typename T>
	void slist<T>::clear() {
		makeEmpty();
		init();
	}

	template<typename T>
	size_t slist<T>::size() const {
		return _size;
	}

	template<typename T>
	bool slist<T>::operator==(const slist<T>& rhs) const {
		if (this == &rhs)
			return true;

		if (size() != rhs.size())
			return false;

		slist_node<T> *  p1 = head->next;
		slist_node<T> *  p2 = rhs.head->next;

		while (p1 != nullptr || p2 != nullptr)
		{
			if (p1->value != p2->value)
				return false;

			p1 = p1->next;
			p2 = p2->next;
		}

		return true;
	}

	template<typename T>
	bool slist<T>::operator!=(const slist<T>& rhs) const {
		return !(*this == rhs);
	}

	template <typename T>
	void slist<T>::copy(const slist<T>& rhs) {
		slist_node<T> *  p = rhs.head->next;
		while (p != nullptr) {
			push_back(p->value);
			p = p->next;
		}
	}

	template<class T>
	void slist<T>::init() {
		header.next = nullptr;
		head = tail = &header;
		_size = 0;
	}

	template<typename T>
	void slist<T>::killNode(slist_node<T>* target) {
		slist_node<T> *  previous = findNodePrevious(target);

		previous->next = target->next;

		if (tail == target)
			tail = previous;

		delete target;

		_size--;
	}

	template<class T>
	void slist<T>::makeEmpty() {
		slist_node<T> *  ptr = head->next;
		slist_node<T> *  target;

		while (ptr != nullptr) {
			target = ptr;
			ptr = ptr->next;
			delete target;
		}
	}

	template<typename T>
	slist_node<T>* slist<T>::findNode(const T & element) const {
		slist_node<T> *  ptr = head->next;
		while (ptr != nullptr &&  ptr->value != element) 
			ptr = ptr->next;

		return ptr;
	}

	template<class T>
	slist_node<T>*  slist<T>::findNodePrevious(slist_node<T> *  node) const {
		slist_node<T> * ptr = head;

		while (ptr->next != nullptr && ptr->next != node)
			ptr = ptr->next;

		return ((ptr->next != nullptr) ? ptr : nullptr);
	}

	template<typename T>
	void slist<T>::remove(const T& element) {
		slist_node<T> *  target = findNode(element);

		if (target == nullptr)
			throw std::logic_error("Node not found.");

		killNode(target);
	}

	template<typename T>
	bool slist<T>::contains(const T & element) const {
		slist_node<T> * node = findNode(element);
		return node != nullptr;
	}
}