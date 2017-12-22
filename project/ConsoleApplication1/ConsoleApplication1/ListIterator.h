#ifndef LISTITERATOR_H
#define LISTITERATOR_H
#include <iostream>
#include "ListNode.h"

namespace cs20a {
	template <class T>
	class List;					// forward declaration

	template <class T>
	class ListIterator {
	public:
		ListIterator();
		bool isValid() const;
		void advance();
		const T& retrieve() const;

	private:
		ListNode<T> * current;

		ListIterator(ListNode<T> *node);

		// List exposes ListIterator instances via public methods
		// no external access should be given to the current pointer
		// friend access is required by List class to ensure this information hiding
		friend class List<T>;
	};
}
#endif