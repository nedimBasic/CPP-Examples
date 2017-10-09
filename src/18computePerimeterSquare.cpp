// Name        : 18computePerimetarsSquare.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Compute perimeter of square if you enter a value of length of side edge
// Learn terms : 1. cin
//               2. cout
//               3. double variable
//               4. operator *
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Please, enter a value of length of side edge of square!" << endl;
	cout << "{Warning: For decimals number you can enter only points as decimal marks!}"<<endl;
	double a; // side edge a of square
	cin>>a;
	cout << "a = " << a << endl;
	double perimeter=0;
	cout << "O = 4*a" << endl;
	perimeter = 4*a;
	cout << "O = " << perimeter << endl;
	return 0;
}
