///============================================================================
// Name        : 05writeAverageThreeNumber.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               1. Create three integer variable with name nb1, nb2 and nb3
//               2. Read three integer number from keyboard using cin
//               3. Create int variable with name avg
//               4. Prints average those number on console using function double(), operator / and cout command
// Learn terms : 1. integer variable
//               2. cin
//               3. cout
//               4. function double()
//               5. operator / and ( )
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Please, put three integer number from keyboard!" << endl; // prints Please, put three integer number from keyboard!
	int nb1,nb2,nb3;
	cin>>nb1>>nb2>>nb3;
	int avg;
	avg=nb1+nb2+nb3;
	cout << "Average of number " << nb1 << ", number " << nb2 << ", number " << nb3 << " is : " << double(avg)/3 << endl;
	return 0;
}
