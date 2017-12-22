// Menu.cpp : Defines the entry point for the console application.
//
#define DOUBLE
#include <iostream>
#include "slist.h"
#include "dlist.h"

using namespace std;
using namespace cs20a;

enum CHOICE { APPEND, REMOVE, CONTAINS, SIZE, MAKEEMPTY, ISEMPTY, QUIT, PRINT, SORTASCENDING, SORTDESCENDING, OTHER };

CHOICE menu();
void printList(slist<int>& l);
void printList(dlist<int>& l);
bool sortAscending(const int &val1, const int &val2);
bool sortDescending(const int &val1, const int &val2);

int main(int argc, char* argv[]) {

#ifdef SINGLE
    slist<int> list;
#else
    dlist<int> list;
#endif

    int value = 0;

    CHOICE choice;
    do {
        choice = menu();
        switch (choice) {
            case MAKEEMPTY:
                list.clear();
                break;
            case ISEMPTY:
                if (list.empty())
                    cout << "List is empty." << endl;
                else
                    cout << "List is not empty." << endl;
                break;
            case SIZE:
                cout << "List has " << list.size() << " elements. " << endl;
                break;
            case REMOVE:
                cout << "Please provide int to remove: ";
                cin >> value;
                list.remove(value);
                break;
            case APPEND:
                cout << "Please provide seed for random number generator: ";
                cin >> value;
                srand(value);
                cout << "Please provide number of nodes: ";
                cin >> value;
                for (int i = 0; i < value; i++)
                    list.push_back(rand() % value);
                break;
            case CONTAINS:
                cout << "Please provide int to find: ";
                cin >> value;
                if (list.contains(value))
                    cout << "List contains " << value << "." << endl;
                else
                    cout << "List does not contain " << value << "." << endl;
                break;
            case PRINT:
                printList(list);
                break;
            case SORTASCENDING:
                list.sort(sortAscending);
                break;
            case SORTDESCENDING:
                list.sort(sortDescending);
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
    cout << "(A)dd Nodes (R)emove (C)ontains (M)akeEmpty (S)ize (I)sEmpty (P)rint (1) Sort Asc (2) Sort Desc (Q)uit: " << endl;
    cin >> choice;
    switch (choice) {
        case 'M':
        case 'm':
            result = MAKEEMPTY;
            break;
        case 'I':
        case 'i':
            result = ISEMPTY;
            break;
        case 'A':
        case 'a':
            result = APPEND;
            break;
        case 'R':
        case 'r':
            result = REMOVE;
            break;
        case 'C':
        case 'c':
            result = CONTAINS;
            break;
        case 'S':
        case 's':
            result = SIZE;
            break;
        case 'P':
        case 'p':
            result = PRINT;
            break;
        case 'Q':
        case 'q':
            result = QUIT;
            break;
        case '1':
            result = SORTASCENDING;
            break;
        case '2':
            result = SORTDESCENDING;
            break;
        default:
            result = OTHER;
            break;
    }

    return(result);
}

void printList(slist<int>& l) {
    if (l.empty())
        cout << "Empty list" << endl;
    else {
        for (slist<int>::iterator it = l.begin(); it != l.end(); it++) {
            cout << *it << " -> ";
        }
        cout << "NULL" << endl;
    }
}

void printList(dlist<int>& l) {
    if (l.empty())
        cout << "Empty list" << endl;
    else {
        for (dlist<int>::iterator it = l.begin(); it != l.end(); it++) {
            cout << *it << " -> ";
        }
        cout << "NULL" << endl;
    }
}

bool sortAscending(const int & val1, const int & val2) {
    return val1 < val2;
}

bool sortDescending(const int & val1, const int & val2) {
    return val1 > val2;
}
