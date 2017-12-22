/*

o Programmer name:	Yu Tian
o Course number:1748
o Date: 10/15
o Purpose: Project 10: Fuller TrashCan
o Input:
o Output:
----some tests follow----
This trash can is destroyed
This trash can is destroyed
A TrashCan with a size=100 and containing 8 pieces of trash. There are 4 trash cans
A TrashCan with a size=5 and containing 0 pieces of trash. There are 4 trash cans
A TrashCan with a size=5 and containing 4 pieces of trash. There are 4 trash cans
A TrashCan with a size=100 and containing 4 pieces of trash. There are 4 trash cans
> is working...
< is working...
!= is working...
< is working...
== is working...
---some broken code follows---
Error: Trash can will be exploded!
This trash can is destroyed
Error: Run out of trash!
This trash can is destroyed

*/
#include "TrashCan.h"
#include <iostream>
#include <stdexcept>
using namespace std;
int TrashCan::numOfTrashCan = 0;

int main( ) {
	
	TrashCan yours(5, 3);
	TrashCan mine(100, 3);
	yours.addItem();
	mine.addItem();

	cout << "----some tests follow----" << endl;

	TrashCan eightItems = mine + mine;
	TrashCan zeroItems = yours - yours;
	cout << eightItems;
	cout << zeroItems;
	cout << yours;
	cout << mine;
	if (eightItems > zeroItems) {
		cout << "> is working..." << endl;
	}
	if (eightItems < zeroItems) {
		cout << "< is not working..." << endl;
	}
	else {
		cout << "< is working..." << endl;
	}
	if (eightItems != zeroItems) {
		cout << "!= is working..." << endl;
	}
	if (zeroItems < eightItems) {
		cout << "< is working..." << endl;
	}
	if (eightItems == eightItems) {
		cout << "== is working..." << endl;
	}

	cout << "---some broken code follows---\n";
	// each of the operator calls below should print out
	// some kind of error message, instead of working correctly...

	TrashCan negativeItems = mine - eightItems;
	//cout << negativeItems;
	TrashCan overfull = yours + yours;
	//cout << overfull;
	int x;
	cin >> x;

	return( 0 );
}