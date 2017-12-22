#include "Wallet.h"

using namespace std;

// Initialising the values of dollars and cents
Wallet::Wallet() {
	my_Dollars = 0;
	my_Cents = 0;
}

Wallet::Wallet(int dollars, int cents) {
	my_Dollars = dollars;
	my_Cents = cents;
}


// Allows user to check the amount of dollars one has in one's wallet
int Wallet::getDollars() {
	return my_Dollars;
}

// Allows user to check the amount of cents one has in one's wallet
int Wallet::getCents() {
	return my_Cents;
}

// Testing before actually purchasing the product, whether one has enough/equal/less balance compare to the purchase
bool Wallet::canPayFor(int dollarAmount, int centsAmount) {
	double B_for_test = 0; //Amount of balance for testing
	double P_for_test = 0; //Amount of purchase for testing
	B_for_test = my_Dollars + (my_Cents*0.01);
	P_for_test = dollarAmount + (centsAmount*0.01);
	if (B_for_test >= P_for_test) {
		return 1;
	}
	else {
		return 0;
	}
}

// The official process for purchasing a product
void Wallet::payFor(int dollarAmount, int centsAmount) {
	double B_official = 0; //Official amount of balance. Used for actual purchasing
	double P_official = 0; //Official amount of purchase. Used for actual purchasing
	double C_official = 0; //Official amount of change. Used for calculating change in amount of money after purchase

	B_official = my_Dollars + (my_Cents*0.01);
	P_official = dollarAmount + (centsAmount*0.01);

	my_Dollars = floor(B_official); //Function used to convert the double value to nearest integer not greater than the given value 
	C_official = B_official - (floor(B_official) * 100);
	C_official = ceil(C_official); // Function used to convert the double value to nearest integer not less than the given value 
	my_Cents = C_official;
}

// The process for withdrawing money from ATM
void Wallet::visitATMForCash(int dollarAmount) {
	my_Dollars += dollarAmount;
}