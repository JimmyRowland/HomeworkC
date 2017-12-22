#pragma once
#include <iostream>
#include "List.h"
#include "ListNode.h"
//using namespace std;
namespace cs20a
{
	template<class T>
	List<T>::List()
	{
		init();
	}

	template<class T>
	List<T>::List(const List &rhs)
	{
		init();
		copy(rhs);
	}

	template<class T>
	List<T>::~List()
	{
		makeEmpty();
	}

	template<class T>
	List<T> & List<T>::operator = (const List<T> &rhs)
	{
		if (this == &rhs)
			return *this;

		makeEmpty();
		init();
		copy(rhs);

		return *this;
	}

	template<class T>
	void List<T>::init()
	{
		head = tail = &header;
		header.next = nullptr;
		size = 0;
	}

	template<class T>
	bool List<T>::isEmpty() const
	{
		return size == 0;
	}

	template<class T>
	void List<T>::copy(const List<T> &rhs)
	{
        if (this == &rhs)
            return;
        ListNode<T>* pointer = head;
		makeEmpty();
		ListNode<T> *listToCopy = rhs.head;
		while(listToCopy->next != nullptr){
			listToCopy=listToCopy->next;
			append(listToCopy->value);
			size++;
		}
		//*** Implement this code ***

	}

	template<class T>
	void List<T>::makeEmpty()
	{
		//*** Implement this code ***
		while(!isEmpty()){
//			cout <<"node to delete: "<<tail->value<<endl;
			tail=tail->previous;
			delete tail->next;
			tail->next= nullptr;
			size--;
//			cout <<"tail after deleting node: "<<tail->value<<". size: "<<getSize()<<endl;
		}
	}

	template<class T>
	void List<T>::append(const T &value)
	{
		//*** Implement this code ***
		tail->next=new ListNode<T>(value);
		tail->next->previous=tail;
		tail->next->next= nullptr;
		tail = tail->next;
		size+=1;
//        for(ListNode<T>* pointer=tail;pointer!=head;pointer=pointer->previous)
//            cout<<pointer->value<<"<<";
//        cout<<endl;
	}

	template<class T>
	bool List<T>::remove(const T &value)
	{
		for(ListNode<T> *pointer = head->next;pointer!= nullptr;pointer=pointer->next){
			if (pointer->value==value){
				pointer->previous->next=pointer->next;
				if (pointer == tail) tail=pointer->previous;
				else pointer->next->previous=pointer->previous;
				delete pointer;
				size-=1;
				return true;

			}
		}
		return false;

	}

	template<class T>
	void List<T>::clear()
	{
		makeEmpty();
		init();
	}

	template<class T>
	bool List<T>::contains(const T &value)
	{
		if (head->next == nullptr)
			return false;

		ListNode<T> *current = head->next;
		while (current != nullptr)
		{
			if (current->value == value)
				return true;

			current = current->next;
		}

		return false;
	}

	template<class T>
	int List<T>::getSize() const
	{
		return size;
	}
}