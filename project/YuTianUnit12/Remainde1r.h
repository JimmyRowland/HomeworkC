#ifndef REMAINDER_H
#define REMAINDER_H
#include <iostream>
using namespace std;


class Remainder {

private:
	int myValueofA;
	int myValueofB;
public:
	Remainder( );
	Remainder( int myValueofA);
	Remainder( int myValueofA, int myValueofB);
	
	int getA() const;
	int getB() const;

	int RecursiveARemainderB() const;
	int IterativeARemainderB() const;
	

	
	~Remainder();
	


};

#endif