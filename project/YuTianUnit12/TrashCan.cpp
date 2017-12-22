#include "TrashCan.h"
#include <iostream>
#include <stdexcept>
TrashCan::TrashCan( ) {
	myIsCovered = false;
	my_Size = 0;
	my_Contents = 0;
	TrashCan::numOfTrashCan++;
}

TrashCan::TrashCan( int size ) {
	myIsCovered = false;
	my_Size = size;
	my_Contents = 0;
	TrashCan::numOfTrashCan++;
}

TrashCan::TrashCan( int size, int contents ) {
	
	
	
	
	try {
		if (trashCanExploded(size, contents) || notEnoughTrash(size, contents)) {
		
		}
		else {
			myIsCovered = false;
			my_Size = size;
			my_Contents = contents;
			TrashCan::numOfTrashCan++;
		}
		
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	
	
	
}

void TrashCan::setSize( int size ) {
	my_Size = size;
}
void TrashCan::removeContents() {
	my_Contents -= 1;
}
int TrashCan::getSize( ) {
	return( my_Size );
}

int TrashCan::getContents( ) {
	return( my_Contents );
}

void TrashCan::addItem( ) {
	my_Contents = my_Contents + 1;
}
	
void TrashCan::empty( ) {
	my_Contents = 0;
}

void TrashCan::cover( ) {
	myIsCovered = true;
}

void TrashCan::uncover( ) {
	myIsCovered = false;
}

void TrashCan::printCan(std::ostream& outs) const{
	using namespace std;
	cout << "A TrashCan with a size=" << my_Size << " and containing " << my_Contents << " piece";
	if (my_Contents != 1) {
		cout << "s";
	}
	cout << " of trash" << ". There are " << numOfTrashCan << " trash cans" << endl;
}
ostream& operator <<(ostream& outs,
	const TrashCan& n) {
	n.printCan(outs);
	return(outs);
}

istream& operator >> (istream& ins,
	TrashCan& n) {
	int i = 0;
	ins >> i;
	n.setSize(i);
	return(ins);
}

TrashCan operator+ (const TrashCan& left, const TrashCan& right) {
	TrashCan temp = TrashCan(left.my_Size,left.my_Contents + right.my_Contents);
	return(temp);
}
TrashCan operator- (const TrashCan& left, const TrashCan& right) {
	TrashCan temp = TrashCan(left.my_Size, left.my_Contents - right.my_Contents);
	return(temp);
}
bool operator== (const TrashCan& left, const TrashCan& right) {
	return(left.my_Contents == right.my_Contents);
}
bool operator!= (const TrashCan& left, const TrashCan& right) {
	return(left.my_Contents != right.my_Contents);
}
bool operator>= (const TrashCan& left, const TrashCan& right) {
	return(left.my_Contents >= right.my_Contents);
}
bool operator<= (const TrashCan& left, const TrashCan& right) {
	return(left.my_Contents <= right.my_Contents);
}
bool operator> (const TrashCan& left, const TrashCan& right) {
	return(left.my_Contents > right.my_Contents);
}
bool operator< (const TrashCan& left, const TrashCan& right) {
	return(left.my_Contents < right.my_Contents);
}

bool TrashCan::trashCanExploded(int size, int contents) {
	if (contents > size) {
		throw "Error: Trash can will be exploded!";
		return true;
	}
	return false;
}
bool TrashCan::notEnoughTrash(int size, int contents) {
	if (contents < 0) {
		throw "Error: Run out of trash!";
		return true;
	}
	return false;
}

TrashCan::~TrashCan() {
	cout << "This trash can is destroyed\n";
	
}
