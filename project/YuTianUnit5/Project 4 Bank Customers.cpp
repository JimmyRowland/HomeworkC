/*

o Programmer name:	Yu Tian
o Course number:1748
o Date: 10/1
o Purpose: Project 4: Bank Customers
o Input: 7040,700,75040,0,0	
o Output:	
Gimme a balance (0 to end): 7040
Gimme a balance (0 to end): 700
Gimme a balance (0 to end): 75040
Gimme a balance (0 to end): 0
Your branch has 2 Regular Customers, 0 Special Customers and 1 VIP Customer
Try again? [1=yes/0=no]: 0
											 
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void const outputClassifiedCustomers(int regular, int special, int vip) {
	cout << "Your branch has " << regular << " Regular Customers, " << special << " Special Customers and " << vip << " VIP Customers\n";
}
int tryAgain() {
	int boolean;
	cout << "Try again? [1=yes/0=no]: ";
	cin >> boolean;
	if (boolean == 1)
		return 1;
}
int inputBalance(int* regular, int* special, int* vip) {
	//cout << *regular;
	cout << "Gimme a balance (0 to end): ";
	int balance;
	cin >> balance;
	if ((balance>=0)==0){
		cout << "Go FAFSA to fund your education, it's really EASY" << endl;
		
		return -1;
	}//if balance is less than 0 or balance is not a number, exit.
	else if (balance == 0) {
		
		outputClassifiedCustomers(*regular, *special, *vip);
		*regular = 0;
		*special = 0;
		*vip = 0;
		if (tryAgain() == 1)
			inputBalance(regular,special,vip);
		return 0;
	}
	else if (balance < 10000) {
		
		(*regular)++;
	}
	else if (balance < 50000) {
		*special+=1;
	}
	else {
		*vip+=1;
	}
	inputBalance(regular, special, vip);
	return 0;
}
int main() {
	cout << "Bank Customer Categorization:\n";
	int regular = 0;
	int special = 0;
	int vip = 0;
	
	inputBalance(&regular, &special, &vip);
	

	
	
	return 0;

}