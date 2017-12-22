//
// dlist - doubly-linked list with iterators
// CS-20A: Data Structures With C++
// Professor Scott E Robertson
// 5/19/2017
//
#pragma once
#include <stdexcept>
#include "compare.h"
namespace cs20a
{
	template <typename T> class dlist;
	template <typename T> class dlist_iterator;
	template <typename T> class const_dlist_iterator;
	template <typename T> class reverse_dlist_iterator;
	template <typename T> class const_reverse_dlist_iterator;

	template <typename T>
	class dlist_node {
		friend class dlist<T>;
		friend class dlist_iterator<T>;
		friend class const_dlist_iterator<T>;
		friend class reverse_dlist_iterator<T>;
		friend class const_reverse_dlist_iterator<T>;

	private:
		dlist_node() {};
		dlist_node(const T& t, dlist_node<T> *prev = nullptr, dlist_node<T> *next = nullptr)
			: value(t), prev(prev), next(next) {};

		T value;
		dlist_node<T> *next, *prev;
	};

	template <typename T>
	class dlist_iterator {
		friend class dlist<T>;

	public:
		T& operator*() const { return np->value; };
		bool operator == (const dlist_iterator<T>& li) const { return np == li.np; };
		bool operator!=(const dlist_iterator<T>& li) const { return np != li.np; };

		const dlist_iterator<T>& operator++() {
			np = np->next;
			return *this;
		};

		const dlist_iterator<T> operator++(int) {
			dlist_iterator<T> clone(*this);
			np = np->next;
			return clone;
		};

	private:
		dlist_node<T> *np;
		dlist_iterator(dlist_node<T> *np) : np(np) {};
	};

	template <typename T>
	class reverse_dlist_iterator {
		friend class dlist<T>;

	public:
		T& operator*() const { return np->value; };
		bool operator == (const reverse_dlist_iterator<T>& li) const { return np == li.np; };
		bool operator!=(const reverse_dlist_iterator<T>& li) const { return np != li.np; };

		const reverse_dlist_iterator<T>& operator++() {
			np = np->prev;
			return *this;
		};

		const reverse_dlist_iterator<T> operator++(int) {
			reverse_dlist_iterator<T> clone(*this);
			np = np->prev;
			return clone;
		};

	private:
		dlist_node<T> *np;
		reverse_dlist_iterator(dlist_node<T> *np) : np(np) {};
	};

	template <typename T>
	class const_dlist_iterator {
		friend class dlist<T>;

	public:
		T const& operator*() const { return np->value; };
		bool operator == (const const_dlist_iterator<T>& li) const { return np == li.np; };
		bool operator!=(const const_dlist_iterator<T>& li) const { return np != li.np; };

		const const_dlist_iterator<T>& operator++() {
			np = np->next;
			return *this;
		};

		const const_dlist_iterator<T> operator++(int) {
			const_dlist_iterator<T> clone(*this);
			np = np->next;
			return clone;
		};

	private:
		const dlist_node<T> *np;
		const_dlist_iterator(const dlist_node<T> *ptr) : np(ptr) {};

	};

	template <typename T>
	class const_reverse_dlist_iterator {
		friend class dlist<T>;

	public:
		T const& operator*() const { return np->value; };

		bool operator == (const const_reverse_dlist_iterator<T>& li) const { return np == li.np; };
		bool operator!=(const const_reverse_dlist_iterator<T>& li) const { return np != li.np; };

		const const_reverse_dlist_iterator<T>& operator++() {
			np = np->prev;
			return *this;
		};

		const const_reverse_dlist_iterator<T> operator++(int) {
			const_reverse_dlist_iterator<T> clone(*this);
			np = np->prev;
			return clone;
		};

	private:
		const dlist_node<T> *np;
		const_reverse_dlist_iterator(const dlist_node<T> *ptr) : np(ptr) {};

	};

	template <typename T>
	class dlist {
	public:
		typedef dlist_iterator<T> iterator;
		typedef const_dlist_iterator<T> const_iterator;
		typedef reverse_dlist_iterator<T> reverse_iterator;
		typedef const_reverse_dlist_iterator<T> const_reverse_iterator;

	public:
		dlist();
		dlist(const dlist<T> &rhs);
		~dlist();

		dlist<T>& operator =(const dlist<T> & rhs);

		bool operator==(const dlist<T> &rhs) const;
		bool operator!=(const dlist<T> &rhs) const;

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
		long size() const;

		void remove(const T& element);
		bool contains(const T& element) const;

		void sort(bool(*comp)(const T &, const T &) = defaultCompare);

		iterator begin() { return dlist_iterator<T>(head->next); }
		iterator end() { return dlist_iterator<T>(nullptr); }
		reverse_iterator rbegin() const { return reverse_dlist_iterator<T>(tail->prev); };
		reverse_iterator rend() const { return reverse_dlist_iterator<T>(nullptr); };
		const_iterator cbegin() const { return const_dlist_iterator<T>(head->next); };
		const_iterator cend() const { return const_dlist_iterator<T>(nullptr); };
		const_reverse_iterator crbegin() const { return const_reverse_dlist_iterator<T>(tail->prev); };
		const_reverse_iterator crend() const { return const_reverse_dlist_iterator<T>(nullptr); };

		iterator insert(iterator position, const T& element) {
			dlist_node<T> * successor = position.np;
			dlist_node<T> * target = new dlist_node<T>(element, successor->prev, successor);

			if (successor->prev != nullptr)
				successor->prev->next = target;

			successor->prev = target;

			if (head->next == successor)
				head->next = target;

			_size++;

			return iterator(target);
		}
		iterator erase(iterator position) {
			dlist_node<T> * successor = position.np->next;
			dlist_node<T> * target = position.np;

			killNode(target);

			return iterator(successor);
		}

	private:
		dlist_node<T> header, tailer, *head, *tail;
		long _size;

		bool(*compare)(const T &, const T &);

		void makeEmpty();
		void init();
		void copy(const dlist<T>& rhs);

		void killNode(dlist_node<T> *target);
		dlist_node<T> * findNode(const T& element) const;
	};

	template <typename T>
	dlist<T>::dlist() {
		init();
	}

	template <typename T>
	dlist<T>::dlist(const dlist<T> &rhs) {
		init();
		copy(rhs);
	}

	template<typename T>
	dlist<T>& dlist<T>::operator=(const dlist<T>& rhs) {
		if (this != &rhs) {
			clear();
			copy(rhs);
		}
		return *this;
	}

	template <typename T>
	dlist<T>::~dlist() {
		makeEmpty();
	}

	template <typename T>
	void dlist<T>::push_back(const T& element) {
		dlist_node<T> *node = new dlist_node<T>(element, tail->prev, nullptr);

		if (empty())
			head->next = node;
		else
			tail->prev->next = node;

		tail->prev = node;
		_size++;
	}

	template<typename T>
	T dlist<T>::pop_back() {
		if (empty())
			throw std::logic_error("Empty list.");

		T element = tail->prev->value;
		killNode(tail->prev);

		return element;
	}

	template <typename T>
	void dlist<T>::push_front(const T& element) {
		dlist_node<T> *node = new dlist_node<T>(element, nullptr, head->next);

		if (empty())
			tail->prev = node;
		else
			head->next->prev = node;

		head->next = node;
		_size++;
	}

	template<typename T>
	T dlist<T>::pop_front() {
		if (empty())
			throw std::logic_error("Empty list.");

		T element = head->next->value;
		killNode(head->next);

		return element;
	}

	template<typename T>
	T& dlist<T>::front() {
		return head->next->value;
	}

	template<typename T>
	const T & dlist<T>::front() const {
		return head->next->value;
	}

	template<typename T>
	T& dlist<T>::back() {
		return tail->prev->value;
	}

	template<typename T>
	const T & dlist<T>::back() const {
		return tail->prev->value;
	}

	template<typename T>
	bool dlist<T>::empty() const {
		return head->next == nullptr;
	}

	template<typename T>
	bool dlist<T>::full() const {
		return false;
	}

	template<typename T>
	void dlist<T>::clear() {
		makeEmpty();
		init();
	}

	template<typename T>
	long dlist<T>::size() const {
		return _size;
	}

	template<typename T>
	bool dlist<T>::operator==(const dlist<T>& rhs) const {
		if (this == &rhs)
			return true;

		if (size() != rhs.size())
			return false;

		dlist_node<T> *ptr1 = head->next;
		dlist_node<T> *ptr2 = rhs.head->next;

		while (ptr1 != nullptr || ptr2 != nullptr)
		{
			if (ptr1->value != ptr2->value)
				return false;

			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		return true;
	}

	template<typename T>
	bool dlist<T>::operator!=(const dlist<T>& rhs) const {
		return !(*this == rhs);
	}

	template <typename T>
	void dlist<T>::copy(const dlist<T>& rhs) {
		dlist_node<T> *p = rhs.head->next;
		while (p != nullptr) {
			push_back(p->value);
			p = p->next;
		}
	}

	template<typename T>
	dlist_node<T>* dlist<T>::findNode(const T & element) const {
		dlist_node<T> *ptr = head->next;
		while (ptr != nullptr && ptr->value != element)
			ptr = ptr->next;

		return ptr;
	}

	template<class T>
	void dlist<T>::init() {
		header.prev = header.next = nullptr;
		tailer.prev = tailer.next = nullptr;
		head = &header;
		tail = &tailer;
		_size = 0;
	}

	template<typename T>
	void dlist<T>::killNode(dlist_node<T>* target) {
		if (target->next != nullptr)
			target->next->prev = target->prev;

		if (target->prev != nullptr)
			target->prev->next = target->next;

		if (head->next == target)
			head->next = target->next;

		if (tail->prev == target)
			tail->prev = target->prev;

		delete target;

		_size--;
	}

	template<typename T>
	void dlist<T>::sort(bool(*comp)(const T &, const T &)) {
		if (_size == 0)
			return;

		//*** Implement this function ***

	}

	template<class T>
	void dlist<T>::makeEmpty() {
		dlist_node<T> *  ptr = head->next;
		dlist_node<T> *  target;

		while (ptr != nullptr) {
			target = ptr;
			ptr = ptr->next;
			delete target;
		}
	}

	template<typename T>
	void dlist<T>::remove(const T& element) {
		dlist_node<T> *target = findNode(element);

		if (target == nullptr)
			throw std::logic_error("Node not found.");

		killNode(target);
	}

	template<typename T>
	bool dlist<T>::contains(const T & element) const {
		dlist_node<T> * node = findNode(element);
		return node != nullptr;
	}
}