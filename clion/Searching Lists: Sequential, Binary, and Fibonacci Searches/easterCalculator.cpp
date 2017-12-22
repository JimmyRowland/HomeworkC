#include <string>
#include <iostream>
#include "easterCalculator.h"
using namespace std;

EasterCalculator::EasterCalculator() {
    cout << "What's the year: ";
    cin >> year;

}
EasterCalculator::EasterCalculator(int year) : year(year) {}

void EasterCalculator::setYear(int year) {
    EasterCalculator::year = year;
}

int EasterCalculator::getYear() const {
    return year;
}

void EasterCalculator::printEasterDay() const {
    string Month[] = { "January","February","March","April","May","June",
                       "July","August","September","October","November","December" };
    int a,b,c,d,e,f,g,h,i,j,k,m, p;
    int MoE, DoE;
    a = year % 19;
    b = year / 100;
    c = year % 100;
    d = b / 4;
    e = b % 4;
    f = (b + 8) / 25;
    g = (b - f + 1) / 3;
    h = ((19 * a) + b - d - g + 15) % 30;
    i = c / 4;
    j = c % 4;
    k = (32 + (2 * e) + (2 * i) - h - j) % 7;
    m = (a + (11 * h) + (22 * k)) / 451;
    MoE = (h + k - (7 * m) + 114) / 31;
    p = (h + k - (7 * m) + 114) % 31;
    DoE = p + 1;
    cout << "Easter Month is " << Month[MoE - 1] << endl;
    cout << "Easter Day is " << DoE << endl;

}

EasterCalculator::~EasterCalculator() {

}


