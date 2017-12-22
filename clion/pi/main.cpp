
#include <string>
#include <iostream>
#include "my_pi_approximator.h"
#include <iomanip>
using namespace std;

int main(void) {
    int x;
    char again;
    while (true) {
        cout << "Enter the number of terms for the calculation's accuracy: ";
        cin >> x;
        cout << "The value of pi calculated till " << x << " terms is: " <<fixed << setprecision(20) << pi(x) << "\n";
        cout << "\nWant to check the program again? (y/n):";
        cin >> again;
        if (again == 'n') break;
    }
    return 0;
}

