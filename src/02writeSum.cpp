///============================================================================
// Name        : 02writeSum.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               1. Create two integer variable with name nb1 and nb2
//               2. Read two integer number from keyboard using cin
//               3. Create integer variable with name sum
//               4. Prints sum those number on console using + and cout command
// Learn terms : 1. integer variable
//               2. cin
//               3. cout
//               4. operator +
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Please, put two integer number from keyboard!" << endl; // prints Please, put two integer number from keyboard!
	int nb1,nb2;
	cin>>nb1>>nb2;
	int sum=0;
	sum=nb1+nb2;
	cout << "Sum of number " << nb1 << " and number " << nb2 << " is : " << sum << endl;
	cout << nb1 << " + " << nb2 << " = " << sum;
	return 0;
}
