//============================================================================
// Name        : 07writeSquareRoot.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               1. Include library math.h
//               2. Create double variable with name nb
//               3. Input double number from keyboard using cin
//               4. Create double variable with name squareRoot
//               5. Prints square root those number on console using function sqrt() and cout command
// Learn terms : 1. library math.h
//               2. double variable
//               3. cin
//               4. cout
//               5. function sqrt()
//============================================================================
#include <math.h>
#include <iostream>
using namespace std;
int main() {
	cout << "Please, put double number from keyboard!" << endl;
	double nb;
	cin>>nb;
	double squareRoot = sqrt(nb);
	cout << "Square  root of number " << nb << ", is : " << squareRoot << endl;
	return 0;
}

