#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>

namespace cs52 {

class ListNode {
public:
	ListNode( const int& theElement = 0, ListNode * nextNode = NULL );

	const int getElement() const;
	void setNext( ListNode * nextNode );
	ListNode * getNext() const;

private:
	int element;
	ListNode* next;
};

}
#endif
