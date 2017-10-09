// Name        : 21calcDiagonalSquare.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Calculate length of diagonal of square if you enter a value of length of side edge
// Learn terms : 1. cin
//               2. cout
//               3. double variable
//               4. operator *
//               5. library math.h
//               6. function sqrt(2)
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	cout << "Please, enter a value of length of side edge of square!" << endl;
	cout << "{Warning: For decimals number you can enter only points as decimal marks!}"<<endl;
	double a; // side edge a of square
	cin>>a;
	cout << "a = " << a << endl;
	double diagonal=0;
	cout << "d = a * sqrt(2)" << endl;
	diagonal = a * sqrt(2);
	cout << "d = " << diagonal << endl;
	return 0;
}



