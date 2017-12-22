// Tells the compiler iostream library which contains the function cout
#include <iostream>

// Allows us to use vectors
#include <vector>

// Allows us to use strings
#include <string>

// Allow us to work with files
#include <fstream>

// Allows functions in the std namespace to be used without their prefix
// std::cout becomes cout
using namespace std;
#include <iterator>
#include"Header.h"

#ifdef __HelloWorld__
int main() {
	int* x = new int[5];
	for (int i = 0; i < 5; i++) {
		x[i] = i;
	}
	int a[5] = { 1,2,3,4,5 };
	int b[6];
	copy(a,a+4,b);
	a[0] = 2;
	cout << a[0]<<endl;
	cout << b[0] << endl;


	int* y = new int[5];
	copy(x, x, y);
	

	y[0] = 2;
	cout << y[0] << x[0] << endl;
	cin.get();
}
#endif