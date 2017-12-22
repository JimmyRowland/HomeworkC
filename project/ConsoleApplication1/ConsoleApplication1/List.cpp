#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

namespace cs20a {
	template <class T>
	List<T>::List() {
		head = tail = new ListNode < T >();
	}

	template <class T>
	List<T>::List(const List<T>& rhs) {
		head = tail = new ListNode < T >;
		*this = rhs;
	}

	template <class T>
	List<T>::~List() {
		makeEmpty();
		delete head;
	}

	template <class T>
	bool List<T>::isEmpty() const {
		return head->next == nullptr;
	}

	template <class T>
	void List<T>::makeEmpty() {
		while (!isEmpty()) {
			remove(first().retrieve());
		}
	}

	template <class T>
	ListIterator<T> List<T>::zeroth() const {
		return(ListIterator<T>(head));
	}

	template <class T>
	ListIterator<T> List<T>::first() const {
		return(ListIterator<T>(head->next));
	}

	template <class T>
	void List<T>::insert_front(const T& data, const ListIterator<T> &iter) {
		if (iter.isValid()) {
			ListNode<T>* newnode = new ListNode<T>(data, iter.current->next);

			if (head == tail)  //*** Set tail for first node entered ***
				tail = newnode;

			iter.current->next = newnode;
		}
	}

	template <class T>
	void List<T>::insert_front(const T& data) {
		
		if (isEmpty()) {
			tail = new ListNode <T>(data);
			head->next = tail;
			//			cout <<"head" <<head->element<<"tail"<<tail->element<<"headnext"<<head->next->element<<endl;
		}
		else {
			//			printf("3running else");

			//            cout << this->head->element << endl;

			head->next = new ListNode <T>(data, head->next);
			//			cout << this->head->element << endl;
		}
		
		
	}

	template <class T>
	void List<T>::insert_back(const T& data)
	{
		if (isEmpty()) {
			tail = new ListNode <T>(data);
			head->next = tail;
		}
		else {
			tail->next = new ListNode<T>(data);
			tail = tail->next;
		}
	}


	template <class T>
	bool List<T>::isDuplicated(const T& data) const
	{
		printf("ttttttttttisDuplicated/n");
		for (ListNode<T>* temp = head->next,int i = 0; temp->next != nullptr; temp = temp->next) {
			
			if (temp->next->element == data) i++;
			if (i == 2) return true;
		}
		



		/*ListNode<T>* temp = findPrevious(data).current;
		if (temp == nullptr)
			return false;
		else {
			//            cout<<"before for"<<temp->element<<endl;
			for (temp = temp->next; temp->next != nullptr; temp = temp->next) {
				//                cout<<temp->element<<endl;
				if (temp->next->element == data)
					return true;
			}
			return false;
		}*/

		return false;
	}

	template <class T>
	ListIterator<T> List<T>::findPrevious(const T& data) const {
		ListNode<T>* node = head;
		while (node->next != nullptr && node->next->element != data) {
			node = node->next;
		}
		if (node->next == nullptr) {
			node = nullptr;
		}
		return ListIterator<T>(node);
	}

	template <class T>
	void List<T>::remove(const T& data) {
		ListIterator<T> iter = findPrevious(data);
		if (iter.isValid()) {
			ListNode<T>* node = findPrevious(data).current;
			if (node->next != nullptr) {
				ListNode<T> *oldNode = node->next;
				node->next = (node->next->next);  // Skip oldNode

				if (tail == oldNode)  // *** Reset tail node, when deleting tail
					tail = node;

				delete oldNode;
			}
		}
	}

	// Deep copy of linked list
	template <class T>
	const List<T>& List<T>::operator =(const List<T>& rhs) {
		if (this != &rhs) {
			makeEmpty();

			ListIterator<T> rightiter = rhs.first();
			ListIterator<T> myiterator = zeroth();
			while (rightiter.isValid()) {
				insert_front(rightiter.retrieve(), myiterator);
				rightiter.advance();
				myiterator.advance();
			}
		}
		return(*this);
	}
}

//template<class T>
//T List<T>::pop_back()
//{
//	if (isEmpty())
//		cout << "Empty List" << endl;

//	ListNode<T> *oldNode = tail;
//	T element = oldNode->element;

//	ListNode<T>* prevNode = findPrevious(tail->element).current;
//	prevNode->next = oldNode->next;

//	tail = prevNode;

//	return element;
//}

//template<class T>
//T List<T>::pop_front()
//{
//	if (isEmpty())
//		cout << "Empty List" << endl;

//	ListNode<T> *oldNode = head->next;
//	T element = oldNode->element;

//	head->next = oldNode->next;
//	if (tail == oldNode)  // *** Reset tail node, when deleting tail
//		tail = head;

//	delete oldNode;

//	return element;
//}
#endif