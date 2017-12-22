// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "stack.h"

using namespace std;
using namespace cs20a;

enum CHOICE { MAKEEMPTY, PUSH, ISEMPTY, POP, TOP, CONSECUTIVE, REVERSE, QUIT, PRINT, OTHER };

CHOICE menu();

int main(int argc, char* argv[]) {
	int value;
	stack<int> stack;

	CHOICE choice;
	do {
		choice = menu();
		switch (choice) {
		case MAKEEMPTY:
			stack.clear();
			break;
		case ISEMPTY:
			if (stack.empty()) {
				cout << "Stack is empty." << endl;
			}
			else {
				cout << "Stack is not empty." << endl;
			}
			break;
		case TOP:
			if (stack.empty())
				cout << "Empty stack." << endl;
			else
				cout << "Value on top: " << stack.pop() << "." << endl;
			break;
		case POP:
			if (stack.empty())
				cout << "Empty stack." << endl;
			else
				cout << "Value on top that got popped: " << stack.pop() << "." << endl;
			break;
		case PUSH:
			cout << "Please provide int to push: ";
			cin >> value;
			stack.push(value);
			break;
		case CONSECUTIVE:
			cout << "Please provide int to check: ";
			cin >> value;
			if (stack.isConsecutive(value)) {
				cout << value << " occurs consecutively." << endl;
			}
			else {
				cout << value << " does not occur consecutively." << endl;
			}
			break;
		case REVERSE:
			if (!stack.empty())
				stack.reverse();
			break;
		case PRINT:
			stack.print();
			cout << endl;
			break;
		case OTHER:
			cout << "Not a valid choice." << endl;
		}

	} while (choice != QUIT);

	return(0);
}

CHOICE menu() {
	char choice;
	CHOICE result;
	cout << "(M)akeEmpty I(s)Empty p(U)sh p(O)p (T)op (C)onsecutive (R)everse (P)rint (Q)uit: " << endl;
	cin >> choice;
	switch (choice) {
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'U':
	case 'u':
		result = PUSH;
		break;
	case 'O':
	case 'o':
		result = POP;
		break;
	case 'T':
	case 't':
		result = TOP;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'C':
	case 'c':
		result = CONSECUTIVE;
		break;
	case 'R':
	case 'r':
		result = REVERSE;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	default:
		result = OTHER;
		break;
	}

	return(result);
}