#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>

namespace cs20a {
	template <class T>
	struct ListNode {
		ListNode() : ListNode(T()) {};
		ListNode(const T& theElement, ListNode<T> * node = nullptr) {
			element = theElement;
			next = node;
		}

		T element;
		ListNode* next;
	};
}
#endif