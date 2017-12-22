#include <iostream>
#include "ListNode.h"

namespace cs52 {

ListNode::ListNode( const int& theElement,
				    ListNode* nextNode ) : element( theElement ), next( nextNode ) {
}

const int ListNode::getElement() const {
	return( element );
}

void ListNode::setNext( ListNode * nextNode ) {
	next = nextNode;
}

ListNode * ListNode::getNext() const {
	return( next );
}

}


