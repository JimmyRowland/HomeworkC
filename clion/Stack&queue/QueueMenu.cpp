// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Queue.h"

using namespace std;
using namespace cs20a;

enum CHOICE { MAKEEMPTY, ENQUEUE, ISEMPTY, DEQUEUE, GETFRONT, COUNT, DECREASING, QUIT, PRINT, OTHER };

CHOICE menu();

int main(int argc, char* argv[]) {
	int value, total;
	queue<int> queue;

	CHOICE choice;
	do {
		choice = menu();
		switch (choice) {
		case MAKEEMPTY:
			queue.clear();
			break;
		case ISEMPTY:
			if (queue.empty()) 
				cout << "Queue is empty." << endl;
			else 
				cout << "Queue is not empty" << endl;
			break;
		case DEQUEUE:
			if (queue.empty())
				cout << "Queue is empty." << endl;
			else
				cout << "Here's the value on top that got dequeued: " << queue.dequeue() << "." << endl;
			break;
		case GETFRONT:
			if (queue.empty())
				cout << "Queue is empty." << endl;
			else
				cout << "Here's the value on top: " << queue.peek() << endl;
			break;
		case ENQUEUE:
			cout << "Please provide int to enqueue: ";
			cin >> value;
			queue.enqueue(value);
			break;
		case DECREASING:
			if (queue.empty()) {
				cout << "Queue is empty." << endl;
			}
			else if (queue.isDecreasing())
				cout << "queue is decreasing" << endl;
			else
				cout << "queue is not decreasing" << endl;
			break;
		case COUNT:
			cout << "Please provide int to count: ";
			cin >> value;
			total = queue.count(value);
			cout << value << " appears " << total << " times. " << endl;
			break;
		case PRINT:
			queue.print();
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

	cout << "(M)akeEmpty I(s)Empty (E)nqueue (D)equeue (G)etFront (C)ount Dec(r)easing (P)rint (Q)uit: " << endl;
	cin >> choice;
	switch (choice) {
	case 'E':
	case 'e':
		result = ENQUEUE;
		break;
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'D':
	case 'd':
		result = DEQUEUE;
		break;
	case 'G':
	case 'g':
		result = GETFRONT;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'C':
	case 'c':
		result = COUNT;
		break;
	case 'R':
	case 'r':
		result = DECREASING;
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