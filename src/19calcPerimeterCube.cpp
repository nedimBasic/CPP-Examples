// Name        : 19calcPerimeterCube.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Calculate perimeter of cube if you enter a value of length of side edge
// Learn terms : 1. cin
//               2. cout
//               3. double variable
//               4. operator *
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Please, enter a value of length of side edge of cube!" << endl;
	cout << "{Warning: For decimals number you can enter only points as decimal marks!}"<<endl;
	double a; // side edge a of cube
	cin>>a;
	cout << "a = " << a << endl;
	double perimeter=0;
	cout << "O = 12*a" << endl;
	perimeter = 12*a;
	cout << "O = " << perimeter << endl;
	return 0;
}
