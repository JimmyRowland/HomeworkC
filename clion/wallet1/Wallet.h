#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <iostream>
#include <cmath>

class Wallet {

public :
	Wallet();
	Wallet(int dollars, int cents);

	int getDollars();
	int getCents();
	bool canPayFor(int dollarAmount, int centsAmount);
	void payFor(int dollarAmount, int centsAmount);
	void visitATMForCash(int dollarAmount);

private :
	int my_Dollars;
	int my_Cents;
};

#endif //WALLET_H
