/*

o Programmer name:	Yu Tian
o Course number:1748
o Date: 10/1
o Purpose: Power Bill Calculator
o Input: -20	2	5	10
o Output:	
PI Calculator
How many terms in the series do you want me to calculate:-20
Sorry Charlie!

PI Calculator
How many terms in the series do you want me to calculate:2
Using the series, 2 terms adds up to 2.66667

PI Calculator
How many terms in the series do you want me to calculate:5
Using the series, 5 terms adds up to 3.33968

PI Calculator
How many terms in the series do you want me to calculate:10
Using the series, 5 terms adds up to 3.04184
											 
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
double calculatePI(int terms) {
	double result;
	if (terms == 1)
		return 4;
	else 
		return 4 / (2 * (double)terms - 1)*((terms % 2 == 1) ? 1 : -1) + calculatePI(terms - 1);
		
	
}

int main() {

	int theNumberOfTerms;

	cout << "PI Calculator\nHow many terms in the series do you want me to calculate:";
	cin >> theNumberOfTerms;
	if ((theNumberOfTerms >= 1)==0) {
		cout << "Sorry Charlie!" << endl;
		cin >> theNumberOfTerms;
		return -1;
	}
	const double pi = calculatePI(theNumberOfTerms);
	cout << "Using the series, " << theNumberOfTerms << " terms adds up to " << pi << endl;
	cin >> theNumberOfTerms;
	
	return 0;

}