//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																												//
//	Jisu Han																									//
//	12/02/2017																									//
//	Purpose: Make a c++ functions that concatenate two linked lists and also remove duplicate entries			//
//			 in a linked list																					//
//																												//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "List.h"
#include "ListNode.h"
#include "Settings.h"

namespace cs52 {

	List::List() {
		head = NULL;
		listSize = 0;
	}

	List::~List() {
#ifdef SHOW_DESTRUCTOR_CALLS
		std::cout << "about to--> makeEmpty();" << std::endl;
#endif
		makeEmpty();
#ifdef SHOW_DESTRUCTOR_CALLS
		std::cout << "about to--> delete( head );" << std::endl;
#endif
		delete(head);
	}

	bool List::isEmpty() const {
		return(head == NULL);
	}

	void List::makeEmpty() {
		while (head != NULL) {
			remove(head->getElement());
		}
	}

	int List::size() const {
		return(listSize);
	}

	void List::insert(const int& data) {
		// place data into a ListNode at the front of the list
		// it will move the head node to behind the node
		//    we create dynamically
		ListNode* temp = head;
		ListNode* newnode = new ListNode(data);
		head = newnode;
		newnode->setNext(temp);
		listSize++;
	}

	void List::remove(const int& data) {
		ListNode* current = head;
		ListNode* previous = NULL;
		ListNode* nodeToRemove = NULL;
		while (current != NULL) {
			// have we found it at the current node???
			if (current->getElement() == data) {
				// found it at head node
				if (previous == NULL) {
					nodeToRemove = head;
					head = head->getNext();
				}
				// found it inside the list somewhere
				else {
					nodeToRemove = current;
					// skip the current node
					previous->setNext(current->getNext());
				}
				delete(nodeToRemove);
				listSize--;
				break;
			}
			// keep looking
			else {
				previous = current;
				current = current->getNext();
			}
		}
	}

	std::ostream& operator << (std::ostream& outs, const List& l) {
		return(l.printList(outs));
	}

	std::ostream& operator << (std::ostream& outs, const List* l) {
		return(l->printList(outs));
	}

	std::ostream& List::printList(std::ostream& outs) const {
		if (isEmpty())
			outs << "Empty List" << std::endl;
		else {
			outs << "List has " << size() << " elements: " << std::endl;
			ListNode* current = head;
			while (current != NULL) {
				outs << current->getElement() << " -> ";
				current = current->getNext();
			}
			outs << " NULL";
			outs << std::endl;
		}
		return(outs);
	}

	void List::concatenate(const List& B) {
		ListNode* temp = B.head;
		while (temp != NULL) {
			append(temp->getElement());
			temp = temp->getNext();
		}
	}

	void List::insertith(const int& data, const size_t& i) {
		ListNode* newNode = new ListNode(data);
		if (isEmpty()) {
			append(data);
		}
		else if (i == 1) {
			newNode->setNext(head);
			head = newNode;
		}
		else {
			ListNode* temp = head;
			for (int c = 1; c<i - 1; c++) {
				temp = temp->getNext();
			}
			newNode->setNext(temp->getNext());
			temp->setNext(newNode);
		}
	}

	void List::removeDups() {
		ListNode* temp1;
		ListNode* temp2;
		ListNode* dup;

		temp1 = head;

		while (temp1 != NULL && temp1->getNext() != NULL) {
			temp2 = temp1;

			while (temp2->getNext() != NULL) {
				if (temp1->getElement() == (temp2->getNext())->getElement()) {
					dup = temp2->getNext();
					temp2->setNext((temp2->getNext())->getNext());
					delete(dup);
				}
				else {
					temp2 = temp2->getNext();
				}
			}
			temp1 = temp1->getNext();
		}
	}

	void List::append(const int& data) {
		if (isEmpty()) {
			head = new ListNode(data);
		}
		else {
			ListNode* temp = head;
			while (temp->getNext() != NULL) {
				temp = temp->getNext();
			}
			temp->setNext(new ListNode(data));
		}
		listSize++;
	}

	double List::front() const {
		return head->getElement();
	}

	double List::back() const {
		ListNode* temp = head;
		while(temp->getNext())
		{temp=head->getNext();}

		return temp->getElement();
	}

	double List::currentNode() const {
		return current->getElement();
	}

	void List::advance() {
		if(current->getNext()){current=current->getNext();}
	}

	void List::reset() {
		current=head;

	}

	std::istream &cs52::operator>>(std::istream &ins, double write_me) {
		return ins>>write_me;
	}


}
