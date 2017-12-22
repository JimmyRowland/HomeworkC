#ifndef LISTITERATOR_CPP
#define LISTITERATOR_CPP

#include "ListIterator.h"

namespace cs20a {
	template <class T>
	ListIterator<T>::ListIterator() : current(NULL) {
		// all assignments occurred above
	}

	template <class T>
	ListIterator<T>::ListIterator(ListNode<T> *node) : current(node) {
		// all assignments occurred above
	}

	template <class T>
	bool ListIterator<T>::isValid() const {
		return((current != NULL));
	}


	template <class T>
	void ListIterator<T>::advance() {
		if (isValid()) {
			current = current->next;
		}
	}

	template <class T>
	const T& ListIterator<T>::retrieve() const {
		if (!(isValid())) throw std::logic_error("Invalid iterator.");
		return(current->element);
	}
}
#endif