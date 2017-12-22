// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "List.h"
#include "List.cpp"
#include "ListIterator.h"
#include "ListIterator.cpp"

using namespace std;
using namespace cs20a;

enum CHOICE { MAKEEMPTY, REMOVE, ISEMPTY, FINDPREVIOUS, INSERTFRONT, INSERTBACK, DUPLICATED, QUIT, PRINT };

CHOICE menu();
void printList(const List<int>& l);

int main(int argc, char* argv[]) {

    int value;
    List<int> list;
    ListIterator<int> iter;

    CHOICE choice;
    do {
        choice = menu();
        switch (choice) {
            case MAKEEMPTY:
                list.makeEmpty();
                break;
            case ISEMPTY:
                if (list.isEmpty()) {
                    cout << "list is empty" << endl;
                }
                else {
                    cout << "list is not empty" << endl;
                }
                break;
            case REMOVE:
                cout << "Please provide int to remove: ";
                cin >> value;
                list.remove(value);
                break;
            case INSERTBACK:
                cout << "Please provide int to insert in back: ";
                cin >> value;
                list.insert_back(value);
                break;
            case INSERTFRONT:
                cout << "Please provide int to insert in front: ";
                cin >> value;
                list.insert_front(value);
                break;
            case DUPLICATED:
                cout << "Please provide int to check for duplicates: ";
                cin >> value;
                if (list.isDuplicated(value))
                    cout << "Duplicates found." << endl;
                else
                    cout << "No duplicates found." << endl;
                break;
            case FINDPREVIOUS:
                cout << "Please provide int to find: ";
                cin >> value;
                iter = list.findPrevious(value);
                if (iter.isValid()) {
                    cout << "previous element = " << iter.retrieve() << endl;
                }
                else {
                    cout << "data element was not found!" << endl;
                }
                break;
            case PRINT:
                printList(list);
                break;
        }

    } while (choice != QUIT);

    return(0);
}

CHOICE menu() {
    char choice;
    CHOICE result;
    cout << "(M)akeEmpty Is(E)mpty Insert(F)ront Insert(B)ack (R)emove FindPre(v)ious (P)rint Is(D)uplicate (Q)uit: " << endl;
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
        case 'F':
        case 'f':
            result = INSERTFRONT;
            break;
        case 'B':
        case 'b':
            result = INSERTBACK;
            break;
        case 'R':
        case 'r':
            result = REMOVE;
            break;
        case 'V':
        case 'v':
            result = FINDPREVIOUS;
            break;
        case 'P':
        case 'p':
            result = PRINT;
            break;
        case 'D':
        case 'd':
            result = DUPLICATED;
            break;
        case 'Q':
        case 'q':
            result = QUIT;
            break;
    }

    return(result);
}

void printList(const List<int>& l) {
    if (l.isEmpty())
        cout << "Empty list" << endl;
    else {
        ListIterator<int> iter = l.first();
        while (iter.isValid()) {
            cout << iter.retrieve() << " -> ";
            iter.advance();
        }
        cout << "NULL";
        cout << endl;
    }
}