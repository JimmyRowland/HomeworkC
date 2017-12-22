#include <iostream>
#include <string>
#include "Wallet1.h"
#include <cmath>
using namespace std;
void thisIsTheDriverGivenByTheProfessor(Wallet myWallet);
int main() {
    Wallet system;
//    system.run_wallet();

    Wallet full(100,50);
    Wallet empty(0,1);
    thisIsTheDriverGivenByTheProfessor(full);
    thisIsTheDriverGivenByTheProfessor(empty);

    return 0;
}

void thisIsTheDriverGivenByTheProfessor(Wallet myWallet){
    cout << "d:" << myWallet.getDollars();
    cout <<" c:" << myWallet.getCents() << endl;
    myWallet.visitATMForCash(50);
    cout << "d:" << myWallet.getDollars();
    cout <<" c:" << myWallet.getCents() << endl;
    if (myWallet.canPayFor(25,35)){
        myWallet.payFor(25,35);
        cout << "buying $25.35 worth..." << endl;
    }
    cout << "d:" << myWallet.getDollars();
    cout <<" c:" << myWallet.getCents() << endl;
    if (myWallet.canPayFor(25,35)){
        myWallet.payFor(25,35);
        cout << "buying $25.35 worth..." << endl;
    }
    cout << "d:" << myWallet.getDollars();
    cout <<" c:" << myWallet.getCents() << endl;
}