#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "ListNode.h"

namespace cs52 {

class List {
public:
	List();
	~List();
    // Implement these!
    void concatenate( const List& B);
    void insertith( const int& data, const size_t& i);
    void removeDups();
    
	bool isEmpty() const;
	int  size() const;
	void makeEmpty();
	void insert( const int& data );
	void remove( const int& data );
	double front() const;
	double back() const;
	double currentNode() const;
	void advance();
	void reset();
	friend std::istream&operator >>(std::istream& ins,double write_me);



	friend std::ostream& operator << ( std::ostream& outs, const List& l );
	friend std::ostream& operator << ( std::ostream& outs, const List* l );
private:
	ListNode* head;
	int listSize;
	ListNode* current;

	std::ostream& printList( std::ostream& outs ) const;
    
    //Implement this!!
    void append( const int& data );
};

}
#endif
