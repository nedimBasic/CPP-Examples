//============================================================================
// Name        : 06writePowNumber.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               1. Include library math.h
//               2. Create integer variable with name nb
//               3. Input integer number from keyboard using cin
//               4. Create int variable with name square
//               5. Prints square those number on console using function pow() and cout command
// Learn terms : 1. library math.h
//               2. integer variable
//               2. cin
//               3. cout
//               4. function pow()
//============================================================================
#include <math.h>
#include <iostream>
using namespace std;
int main() {
	cout << "Please, put integer number from keyboard!" << endl;
	int nb;
	cin>>nb;
	int square;
	square=pow(nb,2);
	cout << "Square of number " << nb << ", is : " << square << endl;
	return 0;
}
