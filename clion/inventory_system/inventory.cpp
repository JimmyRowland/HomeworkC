#include <string>
#include <iostream>
#include "inventory.h"
using namespace std;
Inventory::Inventory() {

}

Inventory::~Inventory() {

}

void Inventory::welcome_message() const {
    cout << "Welcome to Widget Co.!\n" << endl;
}

void Inventory::print_production_status_first_line() const {
    cout << "month:" << month << " Number of widgets onhand: " << widget_onhand << " Number back-ordered: " << widget_back_ordered << endl;
}

char Inventory::prompt_good_or_bad() const {
    char good_or_bad;
    while (good_or_bad != 'g' && good_or_bad != 'b') {
        cout << "Was it a good or bad month?" << endl;

        cin >> good_or_bad;

    }
    return good_or_bad;

}

int Inventory::promt_number_sell() const {
    int sale_number;
    cout << "How many did the sales force sell?" << endl;

    cin >> sale_number;
    return sale_number;
}

char Inventory::prompt_continue() const {

    char yes_or_no;
    while (yes_or_no != 'y' && yes_or_no !='n') {
        cout << "no" << endl;
        cin >> yes_or_no;
    }

    return yes_or_no;
}

void Inventory::update_private_variables(char good_bad, int sale_number) {
    month++;
    int left_on_hand= widget_onhand - widget_back_ordered;
    if (good_bad == 'g') left_on_hand += 123; //do calculation here;
    else left_on_hand += 52;
    left_on_hand-=sale_number;
    if(left_on_hand>=0) {widget_onhand=left_on_hand;widget_back_ordered=0;}
    else {widget_back_ordered=-left_on_hand;widget_onhand=0;}
}
void Inventory::print_status_lastline() const {
    cout << month - 1 << widget_onhand << widget_back_ordered << endl;
}
void Inventory::run_inventory() {
    welcome_message();
    char whether_continue = 'y';
    char good_bad;
    int sale_number = 0;
    while (whether_continue == 'y') {
        print_production_status_first_line();
        good_bad = prompt_good_or_bad();
        sale_number = promt_number_sell();
        whether_continue = prompt_continue();
        update_private_variables(good_bad, sale_number);
    }
    print_status_lastline();
}