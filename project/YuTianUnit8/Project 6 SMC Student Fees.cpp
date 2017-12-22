/*

o Programmer name:	Yu Tian
o Course number:1748
o Date: 10/8
o Purpose: Project 5: Tailor
o Input: 1, 30, 72, 1, 1, 1, 2, 32, 50, 1, 25, 1, 3, 35, 72, 1, 0
o Output:
Tailor Fabric Calculator:
Whaddya want? [1=pants/2=shirts/3=shorts]: 1
Gimme your waist size in inches: 30
Gimme your height size in inches: 72
Pleaded front? [1=yes/0=no]: 1
Baggy Look? [1=yes/0=no]: 1
For your pants, you'll need 389.4 square inches of fabric!
Try again? [1=yes/0=no]: 1


Tailor Fabric Calculator:
Whaddya want? [1=pants/2=shirts/3=shorts]: 2
Gimme your waist size in inches: 32
Gimme your height size in inches: 50
Long sleeves? [1=yes/0=no]: 1
Gimme your arms length in inches: 25
For your shirts, you'll need 234.222 square inches of fabric!
Try again? [1=yes/0=no]: 1


Tailor Fabric Calculator:
Whaddya want? [1=pants/2=shirts/3=shorts]: 3
Gimme your waist size in inches: 35
Gimme your height size in inches: 72
Pockets? [1=yes/0=no]: 1
For your shorts, you'll need 73.025 square inches of fabric!
Try again? [1=yes/0=no]: 0

*/
#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>
using namespace std;
void inputWaistHeight(int* waist, int* height) {
	cout << "Gimme your waist size in inches: ";
	int temp;
	cin >> temp;
	*waist = temp;
	cout << "Gimme your height size in inches: ";
	cin >> temp;
	*height = temp;
}
void const outputClassifiedCustomers(double fabric, string pants_shirts_shorts) {
	cout << "For your " << pants_shirts_shorts << ", you'll need " << fabric << " square inches of fabric!\n";
}
int tryAgain() {
	int boolean;
	cout << "Try again? [1=yes/0=no]: ";
	cin >> boolean;
	if (boolean == 1) {
		cout << "\n\n";
		return 1;
	}


	return 0;
}
double Pleaded_front(int* waist, int* height, double fabric) {
	cout << "Pleaded front? [1=yes/0=no]: ";
	int PleadedFront;
	cin >> PleadedFront;
	switch (PleadedFront) {
	case 1:
		fabric += double(*waist) * 0.1;
		return fabric;
	case 0:
		return fabric;
	default:
		cout << "Please input 0, or 1 next time\n";
		return Pleaded_front(waist, height, fabric);
	}
}
double Baggy_look(int* waist, int* height, double fabric) {
	cout << "Baggy Look? [1=yes/0=no]: ";
	int BaggyLook;
	cin >> BaggyLook;
	switch (BaggyLook) {
	case 1:
		fabric *= 1.1;
		return fabric;
	case 0:
		return fabric;
	default:
		cout << "Please input 0, or 1 next time\n";
		return Baggy_look(waist, height, fabric);
	}
}
int pants(int* waist, int* height) {
	double fabric = 0;
	inputWaistHeight(waist, height);
	fabric += double(*waist) * 10.5;
	fabric += double(*height) * 0.5;
	fabric = Pleaded_front(waist, height, fabric);
	fabric = Baggy_look(waist, height, fabric);
	outputClassifiedCustomers(fabric, "pants");
	return 0;
}
double Long_sleeves(int* waist, int* height, double fabric) {
	cout << "Long sleeves? [1=yes/0=no]: ";
	int LongSleeves;
	cin >> LongSleeves;
	switch (LongSleeves) {
	case 1:
		cout << "Gimme your arms length in inches: ";
		int arms_length;
		cin >> arms_length;
		fabric += double(arms_length) * 4.8;
		return fabric;
	case 0:
		return fabric;
	default:
		cout << "Please input 0, or 1 next time\n";
		return Long_sleeves(waist, height, fabric);
	}
}
int shirts(int* waist, int* height) {
	double fabric = 0;
	inputWaistHeight(waist, height);
	fabric += double(*waist) * 2.875;
	fabric += (double(*height) * 4 / 9);
	cout << "double(*height) * 4 " << typeid(double(*height) * 4).name();
	cout << "double(*height) * 4 / 9" << typeid(double(*height) * 4 / 9).name();
	fabric = Long_sleeves(waist, height, fabric);

	outputClassifiedCustomers(fabric, "shirts");
	return 0;
}
double Pockets(int* waist, int* height, double fabric) {
	cout << "Pockets? [1=yes/0=no]: ";
	int pocket;
	cin >> pocket;
	switch (pocket) {
	case 1:
		fabric *= 1.15;
		return fabric;
	case 0:
		return fabric;
	default:
		cout << "Please input 0, or 1 next time\n";
		return Pockets(waist, height, fabric);
	}
}
int shorts(int* waist, int* height) {
	double fabric = 0;
	inputWaistHeight(waist, height);
	fabric += double(*waist) * 1.3;
	fabric += double(*height) * 0.25;
	fabric = Pockets(waist, height, fabric);
	outputClassifiedCustomers(fabric, "shorts");
	return 0;
}
int Whaddya_want(int* waist, int* height) {
	cout << "Tailor Fabric Calculator:\n";
	int pants_shirts_shorts;
	cout << "Whaddya want? [1=pants/2=shirts/3=shorts]: ";
	cin >> pants_shirts_shorts;

	string pantsShirtsShorts;
	switch (pants_shirts_shorts) {
	case 1:
		pantsShirtsShorts = "pants";
		pants(waist, height);
		break;
	case 2:
		pantsShirtsShorts = "shirts";
		shirts(waist, height);
		break;
	case 3:
		pantsShirtsShorts = "shorts";
		shorts(waist, height);
		break;
	default:
		cout << "Please input 1, 2, or 3 next time\n";
		return Whaddya_want(waist, height);
	}
	if (tryAgain()) {

		*waist = 0;
		*height = 0;

		return Whaddya_want(waist, height);

	}
	else {
		cout << endl;
		return 0;
	}
}


int main() {

	int waist = 0;
	int height = 0;


	Whaddya_want(&waist, &height);




	return 0;

}