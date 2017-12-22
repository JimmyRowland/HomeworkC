// ListDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>

#include "List.h"
#include "ListNode.h"

enum CHOICE { PRINT1STLIST, PRINT2NDLIST, QUIT, INSERT, REMOVE, ISEMPTY, MAKEEMPTY, CONCATENATE, INSERTITH, REMOVEDUPS };
CHOICE menu();

int main(int argc, char* argv[])
{
	using namespace cs52;
	using namespace std;

	List l;
	List l2;
	CHOICE c;
	int value, pos;

  l2.insert(55);
  l2.insert(65);
  l2.insert(75);
  l2.insert(85);

	do {
		c = menu();
		switch( c ) {
		case PRINT2NDLIST:
			cout << l2;
			break;
		case PRINT1STLIST:
			cout << l;
			break;
		case ISEMPTY:
			if (l.isEmpty()) {
				cout << "list is empty" << endl;
			}
			else {
				cout << "list is not empty" << endl;
			}
			break;
		case MAKEEMPTY:
			l.makeEmpty();
			break;
		case INSERT:
			cout << "enter an int to insert:";
			cin  >> value;
			l.insert( value );
			//l.append( value );
			break;
		case REMOVE:
			cout << "enter an int to remove:";
			cin  >> value;
			l.remove( value );
			break;
		case CONCATENATE:
			cout << "doing concatenation" << endl;
			l.concatenate(l2);
			break;
        case INSERTITH:
            cout << "enter an int to insert:";
            cin  >> value;
            cout << "enter the position to insert into:";
            cin  >> pos;
            cout << "inserting into ith position" << endl;
            l.insertith(value, pos);
            break;
        case REMOVEDUPS:
            cout << "removing duplicates" << endl;
            l.removeDups();
            break;
        }
	} while (c != QUIT);

	return( 0 );
}

CHOICE menu() {
	using namespace std;
	char c;
	CHOICE result;
	cout << "i(S)empty (M)akeEmpty (I)nsert (R)emove Print(1)stList Print(2)ndList (C)concatentate I(N)sertIth R(E)moveDups (Q)uit:";
	cin  >> c;
	switch( c ) {
    case 'C':
    case 'c':
        result = CONCATENATE;
        break;
    case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'I':
	case 'i':
		result = INSERT;
		break;
    case 'N':
    case 'n':
        result = INSERTITH;
        break;
    case 'R':
	case 'r':
		result = REMOVE;
		break;
	case '1':
		result = PRINT1STLIST;
		break;
	case '2':
		result = PRINT2NDLIST;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'E':
	case 'e':
		result = REMOVEDUPS;
		break;
	default:
		result = menu();
	}
	return( result );
}
