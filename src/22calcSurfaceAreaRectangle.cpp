// Name        : 22calcSurfaceAreaRectangle.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Calculate surface area of rectangle if you enter a value of length of side edge a i b
// Learn terms : 1. cin
//               2. cout
//               3. double variable
//               4. operator *
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
	double area=0;
	cout << "P = a * b" << endl;
	area = a * b;
	cout << "P = " << area << endl;
	return 0;
}
