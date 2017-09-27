// Name        : 118computePerimetarsSquare.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Compute perimetars of square if you put length of side
// Learn terms : 1. integer variable
//               2. cin
//               3. cout
//               4. double variable
//               5. operator *
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Please, put length of side a of square" << endl;
	int a; // side a of square
	cin>>a;
	double perimetars=0;
	perimetars = 4*a;
	cout << "Perimetars of square is " << perimetars << endl;
	return 0;
}
