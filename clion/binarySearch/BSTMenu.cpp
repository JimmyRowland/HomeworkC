//  BSTMenu.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "bst.h"

using namespace std;
using namespace cs20a;

void printValue(const int &value);

enum CHOICE { MAKEEMPTY, ISEMPTY, INSERT, REMOVE, QUIT, PRINT, INORDER, PREORDER, POSTORDER, OTHER };
CHOICE menu();

int main(int argc, char* argv[]) {
	int value;
	bst<int> bst;

	CHOICE choice;
	do {
		choice = menu();
		switch (choice) {
		case MAKEEMPTY:
			bst.clear();
			break;
		case ISEMPTY:
			if (bst.empty()) {
				cout << "Tree is empty." << endl;
			}
			else {
				cout << "Tree is not empty." << endl;
			}
			break;
		case REMOVE:
			if (bst.empty())
				cout << "Empty tree." << endl;
			else
				cout << "Please provide int to remove: ";
			cin >> value;
			bst.remove(value);
			break;
		case INSERT:
			cout << "Please provide int to insert: ";
			cin >> value;
			bst.insert(value);
			break;
		case PRINT:
			bst.print();
			cout << endl;
			break;
		case INORDER:
			cout << "InOrder Traversal:" << endl;
			bst.inOrder(printValue);
			break;
		case PREORDER:
			cout << "PreOrder Traversal:" << endl;
			bst.preOrder(printValue);
			break;
		case POSTORDER:
			cout << "PostOrder Traversal:" << endl;
			bst.postOrder(printValue);
			break;
		case OTHER:
			cout << "Not a valid choice." << endl;
			break;
		}

	} while (choice != QUIT);

	return(0);
}

CHOICE menu() {
	char choice;
	CHOICE result;
	cout << "(M)akeEmpty Is(E)mpty (I)nsert (R)emove (P)rint (1) InOrder (2) PreOrder (3) PostOrder (Q)uit: " << endl;
	cin >> choice;
	switch (choice) {
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'E':
	case 'e':
		result = ISEMPTY;
		break;
	case 'I':
	case 'i':
		result = INSERT;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'R':
	case 'r':
		result = REMOVE;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	case '1':
		result = INORDER;
		break;
	case '2':
		result = PREORDER;
		break;
	case '3':
		result = POSTORDER;
		break;
	default:
		result = OTHER;
		break;
	}

	return(result);
}

void printValue(const int & value)
{
	cout << value << endl;
}
