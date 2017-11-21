// Name        : 27calcPerimeterCircle.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Calculate perimeter of circle, enter a value of the radius r
//               Formula the circumference or perimeter of circle is:
//               	O = 2 · π · r
//               where:
//				 	r  is the radius of the circle
//				 	π  is PI, approximately 3.1415
// Learn terms : 1. cin
//               2. cout
//               3. double variable
//               4. operator *
//               5. define constant number PI (π)
//============================================================================

#include <iostream>
#include <math.h>
#define PI 3.1415
using namespace std;

int main() {
	cout << "{Warning: For decimals number you can enter only points as decimal marks!}"<<endl;
	cout << "Please, enter a value of the radius r of the circle!" << endl;
	double r; // variable r for input value of the radius r of the circle
	cin >> r;
	cout << "r = " << r << endl;
	double O;
	cout << "O =  2 * PI * r" << endl;
	O = 2 * PI * r;
	cout << "O =  " << O << endl;
	return 0;
}
