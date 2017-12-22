

#include "Wallet.h"
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

Wallet::Wallet(double a, double b) : a(a), b(b) {}

void Wallet::setA() {
    //Prompt - Asking for how much did customer hand in for the purchase//
    cout << "Enter a value :";
    //User Input - the whole amount of money that customer hand in//
    cin >> a;
    while(a==0){
        cout << "Enter a value :";
        cin >> a;
    }
}

void Wallet::setB() {
    //Prompt - Asking for sum of the prices of the products that customer wants to buy//
    cout << "Enter an amount of purchases made against this amount : ";

    //User input - the sum of the prices of the products//
    cin >> b;
    while(b==0){
        cout << "Enter a value :";
        cin >> b;
    }
}

void Wallet::printChange() {
    if (b>a)
    {
        cout << "purchases cannot exceed cash value " << endl;
    }

        //Case when the sum of the prices of the products is less than the sum of the money that customer hand in//
    else
    {
        //For 50 cents, quarter, dime, nickel, one cents
        //$20, $10, $5, $1 bills

        double r = a - b;

        //Prints out the remaining change against the purchase of the customer//
        cout << "The remaining change is:" << r << endl;

        //This prints out how many $20 bills included in the change//
        cout << "Twenty US Dollar Bills: " << (int)((int)r / 20) << endl;
        r = r - (int)((int)r / 20) * 20;

        //This prints out how many $10 bills included in the change//
        cout << "Ten US Dollar Bills: " << (int)((int)r / 10) << endl;
        r = r - (int)((int)r / 10) * 10;

        //This prints out how many $5 bills included in the change//
        cout << "Five US Dollar Bills: " << (int)((int)r / 5) << endl;
        r = r - (int)((int)r / 5) * 5;

        //This prints out how many $1 bills included in the change//
        cout << "One US Dollar Bills: " << ((int)r) << endl;
        r = r - (int)r;

        //Counts of cents//
        double i = r;
        string s;
        string t;
        stringstream out;
        out << i;
        s = out.str();
        t = s.substr(s.find(".") + 1);
        int digits = t.length();
        r = (r*pow(10, digits));
        int r1 = (int)r;

        //This prints out how many 50 cents included in the change//
        cout << "Fifty US Cents Coins: " << (int)(r1 / 50) << endl;
        r1 = r1 - (int)(r1 / 50) * 50;

        //This prints out how many quarters included in the change//
        cout << "Twenty-Fifty US Cents Coins: " << (int)(r1 / 25) << endl;
        r1 = r1 - (int)(r1 / 25) * 25;

        //This prints out how many dimes included in the change//
        cout << "Ten US Cents Coins: " << (int)(r1 / 10) << endl;
        r1 = r1 - (int)(r1 / 10) * 10;

        //This prints out how many 5 cents included in the change//
        cout << "Five US Cents Coins: " << (int)(r1 / 5) << endl;
        r1 = r1 - (int)(r1 / 5) * 5;

        //This prints out how many 1 cents included in the change//
        cout << "One US Cents Coins: " << r1 << endl;
        r1 = 0;
}}

Wallet::Wallet() {
    setA();
    setB();
}

Wallet::~Wallet() {

}

void Wallet::setA(double cash) {
    Wallet::a=cash;
}

void Wallet::setB(double cash) {
    Wallet::b=cash;
}

double Wallet::getA() const {
    return a;
}

double Wallet::getB() const {
    return b;
}
