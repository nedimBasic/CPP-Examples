//============================================================================
// Name        : readWriteNumber.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               1. Read integer number from keyboard using cin
//               2. Create integer variable with name number
//               3. Prints those number on console using cout command
// Learn terms : 1. cout
//               2. integer variable
//               3. cin
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Please, put integer number from keyboard!" << endl; // prints Please, put integer number from keyboard!
	int number;
	cin>>number;
	cout << "Number that you put from keyboard is: " << number << endl;
	return 0;
}


