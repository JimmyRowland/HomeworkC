#pragma once
#include <iostream>
#include "ListNode.h"
#include "ListIterator.h"

namespace cs20a
{
	template<class T>
	ListIterator<T>::ListIterator() : m_ptr(nullptr)
	{}

	template<class T>
	ListIterator<T>::ListIterator(ListNode<T>* ptr) : m_ptr(ptr)
	{}

	template<class T>
	ListIterator<T> & ListIterator<T>::operator ++ () // Pre-increment
	{
		m_ptr = m_ptr->next;
		return *this;
	} 
	
	template<class T>
	ListIterator<T>  ListIterator<T>::operator ++ (int) // Post-increment
	{
		ListIterator<T> tmp(*this);
		m_ptr = m_ptr->next;
		return tmp;
	} 

	template<class T>
	T & ListIterator<T>::getValue() const
	{
		return m_ptr->value;
	}

	template<class T>
	bool ListIterator<T>::operator == (const ListIterator<T>& li) const
	{
		return m_ptr==li.m_ptr;
	}

	template<class T>
	bool ListIterator<T>::operator != (const ListIterator<T>& li) const
	{
		return m_ptr!=li.m_ptr;
	}

	template<class T>
	T & ListIterator<T>::operator* () const
	{
		return m_ptr->value;
	}
}