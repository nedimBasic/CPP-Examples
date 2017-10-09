// Name        : 24calcDiagonalRectangle.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Calculate diagonal of rectangle if you enter a value of length of side edge a i b
// Learn terms : 1. cin
//               2. cout
//               3. double variable
//               4. operator * and +
//               5. sqrt()
//               6. library math.h
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	cout << "{Warning: For decimals number you can enter only points as decimal marks!}"<<endl;
	cout << "Please, enter a value of length of side edge a of rectangle!" << endl;
	double a; // side edge a of rectangle
	cin >> a;
	cout << "Please, enter a value of length of side edge b of rectangle!" << endl;
	double b; // side edge b of rectangle
	cin >> b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	double diagonal=0;
	cout << "d = sqrt(a*a + b*b)" << endl;
	diagonal = sqrt(a*a + b*b);
	cout << "d = " << diagonal << endl;
	return 0;
}
