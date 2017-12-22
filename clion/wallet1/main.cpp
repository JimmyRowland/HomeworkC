#include "Wallet.h"

using namespace std;

int main() {

	Wallet w;
	
	cout << "-------------------------------" << endl;
	cout << "Case 1: When Balance > Purchase" << endl;
	cout << "-------------------------------" << endl;
	cout << "Dollars: " << w.getDollars();
	cout << " Cents: " << w.getCents() << endl;

	cout << "After ATM withdrawl, you have 50 dollars more now" << endl;
	w.visitATMForCash(50);

	cout << "New amount of dollars: " << w.getDollars();
	cout << " New amount of cents: " << w.getCents() << endl;

	if (w.canPayFor(25, 35)) {
		cout << "Enough balance, purchase available" << endl;
		w.payFor(25, 35);
		cout << "Buying $25.35 worth..." << endl;
	}
	else
		cout << "Not enough balance, purchase inavailable" << endl;

	cout << "Amount of dollars after purchase: " << w.getDollars();
	cout << " Amount of cents after purchase: " << w.getCents() << endl << endl;

	cout << "-------------------------------" << endl;
	cout << "Case 2: When Balance = Purchase" << endl;
	cout << "-------------------------------" << endl;
	cout << "Dollars: " << w.getDollars();
	cout << " Cents: " << w.getCents() << endl;

	cout << "After ATM withdrawl, you have 25 dollars more than now" << endl;
	w.visitATMForCash(25);

	cout << "New amount of dollars: " << w.getDollars();
	cout << " New amount of cents: " << w.getCents() << endl;
	
	if (w.canPayFor(49, 65)) {
		cout << "Your balance is exactly same as your purchase" << endl;
		w.payFor(49, 65);
		cout << "Buying $49.65 worth..." << endl;
	}
	else
		cout << "Not enough balance, purchase inavailable" << endl;

	cout << "Amount of dollars after purchase: " << w.getDollars();
	cout << " Amount of cents after purchase: " << w.getCents() << endl << endl;

	cout << "-------------------------------" << endl;
	cout << "Case 3: When Balance < Purchase" << endl;
	cout << "-------------------------------" << endl;
	cout << "Dollars: " << w.getDollars();
	cout << " Cents: " << w.getCents() << endl;

	cout << "After ATM withdrawl, you have 100 dollars more than now" << endl;
	w.visitATMForCash(100);

	cout << "New amount of dollars: " << w.getDollars();
	cout << " New amount of cents: " << w.getCents() << endl;

	if (w.canPayFor(150, 25)) {
		cout << "Enough balance, purchase available" << endl;
		w.payFor(150, 25);
		cout << "Buying $150.25 worth..." << endl;
	}
	else
		cout << "Not enough balance, purchase inavailable" << endl;

	cout << "Amount of dollars after purchase: " << w.getDollars();
	cout << " Amount of cents after purchase: " << w.getCents() << endl;

	return 0;
}