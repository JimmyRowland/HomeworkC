// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "List.h"
#include "List.cpp"
#include "ListIterator.h"
#include "ListIterator.cpp"

using namespace std;
using namespace cs20a;

enum CHOICE { APPEND, REMOVE, CONTAINS, SIZE, MAKEEMPTY, ISEMPTY, QUIT, PRINT, OTHER };

CHOICE menu();
void printList(List<int>& l);

int main(int argc, char* argv[]) {

    int value;
    List<int> list;
    ListIterator<int> iter;

    CHOICE choice;
    do {
        choice = menu();
        switch (choice) {
            case MAKEEMPTY:
                list.clear();
                break;
            case ISEMPTY:
                if (list.isEmpty()) {
                    cout << "List is empty." << endl;
                }
                else {
                    cout << "List is not empty." << endl;
                }
                break;
            case SIZE:
                cout << "List has " << list.getSize() << " elements. " << endl;
                break;
            case REMOVE:
                cout << "Please provide int to remove: ";
                cin >> value;
                list.remove(value);
                break;
            case APPEND:
                cout << "Please provide int to append: ";
                cin >> value;
                list.append(value);
                break;
            case CONTAINS:
                cout << "Please provide int to find: ";
                cin >> value;
                if (list.contains(value))
                    cout << "List contains " << value << "." << endl;
                else
                    cout << "List does not contain " << value  << "." << endl;
                break;
            case PRINT:
                printList(list);
                break;
            case OTHER:
                cout << "Not a valid choice." << endl;

        }

    } while (choice != QUIT);

//    List<int> testCopyList;
//    printList(testCopyList);
//    testCopyList.append(123);
//    testCopyList.append(123);
//    printList(testCopyList);
//    testCopyList=list;
//    testCopyList.append(123);
//    list.append(456);
//    printList(testCopyList);
//    printList(list);
//    int x;
//    cin >> x;


    return(0);
}

CHOICE menu() {
    char choice;
    CHOICE result;
    cout << "(A)ppend (R)emove (C)ontains (M)akeEmpty (S)ize (I)sEmpty (P)rint (Q)uit: " << endl;
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

        default:
            result = OTHER;
            break;
    }

    return(result);
}

void printList(List<int>& l) {
    if (l.isEmpty())
        cout << "Empty list" << endl;
    else {
        for (List<int>::iterator it = l.begin(); it != l.end(); it++) {
            cout << *it << " -> ";
        }

        cout << "NULL" << endl;
    }

}