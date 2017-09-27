///============================================================================
// Name        : 02writeSquare.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               1. Create integer variable with name nb
//               2. Read integer number from keyboard using cin
//               3. Create integer variable with name square
//               4. Prints square those number on console using * and cout command
// Learn terms : 1. integer variable
//               2. cin
//               3. cout
//               4. operator *
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Please, put integer number from keyboard!" << endl; // prints Please, put integer number from keyboard!
	int nb;
	cin>>nb;
	int square=1;
	square=nb*nb;
	cout << "Square of number " << nb << " is : " << square << endl;
	cout <<  square << " = " << nb << " * " << nb ;
	return 0;
}




