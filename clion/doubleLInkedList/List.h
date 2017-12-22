#pragma once
#include "ListNode.h"
#include "ListIterator.h"
#include "ListIterator.cpp"
namespace cs20a
{
	template<class T> class ListIterator;

	template <class T>
	class List
	{
	public:
		typedef ListIterator<T> iterator;

		List();
		List(const List &rhs);

		~List();

		List<T> & operator = (const List<T> &rhs);

		//*** Implement these methods only. ***

		void append(const T &value);
		bool remove(const T &value);

		//*** *** *** *** *** *** *** *** ***

		void clear();

		bool contains(const T &value);
		bool isEmpty() const;

		int getSize() const;

		iterator begin()
		{ return iterator(head->next); }

		iterator end()
		{ return iterator(nullptr); }

	private:
		ListNode<T> *head;
		ListNode<T> *tail;

		ListNode<T> header;

		int size;

		void init();

		//*** Implement these methods only. ***

		void copy(const List<T> &rhs);
		void makeEmpty();

		//*** *** *** *** *** *** *** *** ***
	};
}