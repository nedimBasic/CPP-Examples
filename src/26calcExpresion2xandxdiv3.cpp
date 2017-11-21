// Name        : 25calcExpresion2xandxdiv3.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Calculate expression 2x and a/3, enter a value of x and value of a
// Learn terms : 1. cin
//               2. cout
//               3. double variable
//               4. operator * and + and /
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	cout << "{Warning: For decimals number you can enter only points as decimal marks!}"<<endl;
	cout << "Please, enter a value of number x!" << endl;
	double x; // variable x for input value
	cin >> x;
	cout << "x = " << x << endl;
	cout << "2 * x = " << 2*x << endl;
	cout << "Please, enter a value of a!" << endl;
	double a; // side edge a of rectangle
	cin >> a;
	cout << "a = " << a << endl;
	cout << "a / 3 = " << a / 3 << endl;
	return 0;
}
