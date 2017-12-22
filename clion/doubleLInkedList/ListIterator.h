#pragma once
#include "ListNode.h"
namespace cs20a
{
	template <class T>
	class ListIterator
	{
	public:
		ListIterator();
		ListIterator(ListNode<T>* ptr);

		ListIterator<T> & operator ++ ( ); 
		ListIterator<T> operator ++ (int);

		bool operator == (const ListIterator<T>& li) const; 
		bool operator != (const ListIterator<T>& li) const; 

		T & getValue() const; 

		T & operator * () const;

	private:
		ListNode<T>* m_ptr;

	};
}