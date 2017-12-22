//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																														//
//	Jisu Han																											//
//	09/25/2017-09/30/2017																								//
//	Purpose: Calculate the amount of change needed for the purchase against the user's payment							//
//			 This returns the whole amount of cash, as well as kinds of dollar bills, and coins return for the change	//
//	Input: 100,13.25,y,y																			//
//																														//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Output:
//Enter a value :100
//Enter an amount of purchases made against this amount : 13.25
//The remaining change is:86.75
//Twenty US Dollar Bills: 4
//Ten US Dollar Bills: 0
//Five US Dollar Bills: 1
//One US Dollar Bills: 1
//Fifty US Cents Coins: 1
//Twenty-Fifty US Cents Coins: 1
//Ten US Cents Coins: 0
//Five US Cents Coins: 0
//One US Cents Coins: 0
//Continue(y/n)? y
//        The remaining change is:73.5
//Twenty US Dollar Bills: 3
//Ten US Dollar Bills: 1
//Five US Dollar Bills: 0
//One US Dollar Bills: 3
//Fifty US Cents Coins: 0
//Twenty-Fifty US Cents Coins: 0
//Ten US Cents Coins: 0
//Five US Cents Coins: 1
//One US Cents Coins: 0
//Continue(y/n)? y
//        The remaining change is:60.25
//Twenty US Dollar Bills: 3
//Ten US Dollar Bills: 0
//Five US Dollar Bills: 0
//One US Dollar Bills: 0
//Fifty US Cents Coins: 0
//Twenty-Fifty US Cents Coins: 1
//Ten US Cents Coins: 0
//Five US Cents Coins: 0
//One US Cents Coins: 0
//Continue(y/n)?

#include "Wallet.h"
#include <iostream>
using namespace std;
int main(){
    string check = "y";
    Wallet wallet = Wallet();
    wallet.printChange();
    cout << "Continue(y/n)? ";
    cin >> check;
    while (check == "y"){
        wallet.setA(wallet.getA()-wallet.getB());
        wallet.printChange();
        cout << "Continue(y/n)? ";
        cin >> check;
    }




    system("pause");
    return 0;
}