#include <string>
#include <iostream>
#include "Wallet1.h"
#include <cmath>
#include <tuple>
using namespace std;
Wallet::Wallet() {
    my_Dollars = 0;
    my_Cents = 0;
}

Wallet::Wallet(int dollars, int cents) {
    my_Dollars = dollars;
    my_Cents = cents;
}


int Wallet::getDollarsThisIsNotAGetter() {
    cout << "How much do you have? (Sum of Dollars): ";
    cin >> my_Dollars;

    return my_Dollars;
}

int Wallet::notAGettergetCents() {
    cout << "How much do you have? (Sum of cents): ";
    cin >> my_Cents;

    return my_Cents;
}

double Wallet::getBalance() const{
    double my_Balance;
    my_Balance = my_Dollars + my_Cents*.01;
//    cout << "Your current balance is: $" << my_Balance << endl;

    return my_Balance;
}

double Wallet::getPurchase(int dollar, int cent) {
    //	int purchase;
    //	my_Purchase = purchase;
//    cout << "How much do you want to purchase?: ";
    double my_Purchase=  dollar + cent*.01;

    return my_Purchase;
}

void Wallet::ThisIsFineButTheProfessorWillProbablyRunYourClassAgainstADriver_visitATMForCash(int dollarAmount) {
    char yes_or_no = 'x';
    while (yes_or_no != 'y' && yes_or_no != 'n') {
        cout << "Do you want to withdraw from ATM? (y/n)";
        cin >> yes_or_no;
    }
    if (yes_or_no == 'y') {
        cout << "How much do you want to withdraw? :";
        cin >> dollarAmount;
    }
    else
        cout << "No withdraw made" << endl;

    my_Dollars += dollarAmount;
    cout << "Your balance after withdrawal is $" << getBalance() << endl;
}

bool Wallet::canPayFor(int dollarAmount, int centsAmount) {
    //my_Balance = my_Dollars + my_Cents*0.01;
    //my_Purchase = dollarAmount + centsAmount*0.01;
    if (getBalance() >= getPurchase(dollarAmount,centsAmount)) {
//        cout<<getBalance()<<getPurchase(dollarAmount,centsAmount)<<endl;
        cout << "Enough balance, payment available" << endl;
        return true;
    }
//    else {
        cout << "Not enough balance, payment inavailable" << endl;
        return false;
//    }
}

void Wallet::payFor(int dollarAmount, int centsAmount) {
    //	my_Balance = my_Dollars + my_Cents*0.01;
//    my_Purchase = dollarAmount + centsAmount*0.01;
//    my_Balance -= my_Purchase;
    double myBalance= getBalance()-getPurchase(dollarAmount,centsAmount);
    my_Dollars=int(floor(myBalance));
    my_Cents=int(floor((myBalance-my_Dollars)*100));

}

/*void Wallet::changeAmount() {
my_Dollars = trunc(my_Balance);
my_change = my_Balance - trunc(my_Balance)*0.01;
my_Cents = my_change;
}*/

void Wallet::balanceUpdate(int dollarAmount, int centsAmount) {
    payFor(dollarAmount,centsAmount);

    cout << "Your balance after payment is $" << getBalance() << endl;
}

char Wallet::prompt_continue() const {

    char yes_or_no = 'r';
    while (yes_or_no != 'y' && yes_or_no != 'n') {
        cout << "Continue (y/n)?" << endl;
        cin >> yes_or_no;
    }

    return yes_or_no;
}

void Wallet::print_status_lastline() const {

    cout << "Your final balance is $" << getBalance() << endl;
}

void Wallet::run_wallet() {
    // This Driver works but you should use the driver given by the professor (the one in the picture). CS people are lazy
    // Do not expect the professor read your code.
    char whether_continue = 'y';
    int dollarAmount = 0;
    int centsAmount = 0;
    int sale_number = 0;
    while (whether_continue == 'y') {
        //getDollarsThisIsNotAGetter();
        promptGetDollar();
        //notAGettergetCents();
        promptGetCents();
        getBalance();
//        getPurchase();
        tie(dollarAmount,centsAmount)=promptPurchaseAmout();
        ThisIsFineButTheProfessorWillProbablyRunYourClassAgainstADriver_visitATMForCash(dollarAmount);
        canPayFor(dollarAmount, centsAmount);
//        payFor(dollarAmount, centsAmount);
        balanceUpdate(dollarAmount, centsAmount);
        whether_continue = prompt_continue();
    }
    print_status_lastline();
}

int Wallet::getCents() const {
    return my_Cents;
}

void Wallet::setMy_Cents(int my_Cents) {
    Wallet::my_Cents = my_Cents;
}

void Wallet::promptGetDollar() {
    int dollar;
    cout << "How much do you have? (Sum of Dollars): ";
    cin >> dollar;
    dollarSetter(dollar);
}

int Wallet::getDollars() const {
    return my_Dollars;
}

void Wallet::dollarSetter(int dollar) {
    my_Dollars=dollar;
}

void Wallet::promptGetCents() {
    int cents;
    cout << "How much do you have? (Sum of cents): ";
    cin >> cents;

    setMy_Cents(cents);
}

void Wallet::visitATMForCash(int dollar) {
    my_Dollars+=dollar;
}

std::tuple<int, int> Wallet::promptPurchaseAmout() {
    cout << "How much do you want to purchase?: "<<endl;
    cout << "dollar?: "<<endl;
    int dollar, cents;
    cin >> dollar;
    cout << "cents?: "<<endl;
    cin >> cents;
    return make_tuple(dollar,cents);

}
