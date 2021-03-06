#ifndef WALLET_H
#define WALLET_H
class Wallet {
public:
	Wallet();
	Wallet(int d, int c);

	int getDollarsThisIsNotAGetter(); // Getter and setter are both integrated in this method which is not ideal.
    void promptGetDollar();

    int getDollars() const;
    // A class should have getters to desired private variables.
    // A getter should not modify private variable. the const means no private variable is changed
    void dollarSetter(int dollar);
    // Dollar should also have a corresponding setter which passes the value to the private variable.
    // You might want to read about object oriented programming.

    int notAGettergetCents();
    void promptGetCents();

    // The setter and getter below are generated by Clion, VS2017 should have the same functionality.
    int getCents() const;
    void setMy_Cents(int my_Cents);

    double getBalance() const;
	double getPurchase(int dollar, int cent);
	std::tuple<int,int> promptPurchaseAmout();


	void ThisIsFineButTheProfessorWillProbablyRunYourClassAgainstADriver_visitATMForCash(int dollarAmount);
	void visitATMForCash(int dollar);
	bool canPayFor(int dollarAmount, int centsAmount);
	void payFor(int dollarAmount, int centsAmount);
	void balanceUpdate(int dollarAmount, int centsAmount);

	char prompt_continue() const;

	void print_status_lastline() const;

	void run_wallet();



private:
	int my_Dollars = 0;
	int my_Cents = 0;
	//The data below is repetitive
//	double my_Balance = 0.00;
	// This is a physical wallet, Physical wallet can't remember purchases.
//	double my_Purchase = 0.00;
};
#endif //WALLET_H