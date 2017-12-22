#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "ListNode.h"
#include "ListIterator.h"

namespace cs20a {

	template <class T>
	class List {
	public:
		List();
		List(const List& rhs);
		~List();

		bool isEmpty() const;
		void makeEmpty();

		ListIterator<T> zeroth() const;
		ListIterator<T> first() const;

		void insert_front(const T& data, const ListIterator<T> &iter);

		//*** Implement these methods only. ***

		void insert_front(const T& data);
		void insert_back(const T& data);

		bool isDuplicated(const T& data) const;

		//*** *** *** *** *** *** *** *** ***

		ListIterator<T> findPrevious(const T& data) const;

		void remove(const T& data);

		const List& operator =(const List& rhs);

	private:
		ListNode<T> *head, *tail;

	};
}
#endif
