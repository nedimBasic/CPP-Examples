///============================================================================
// Name        : 08calcSumSquareTwoNumber.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               1. Create two integer variable with name nb1 and nb2
//               2. Read two integer number from keyboard using cin
//               3. Create two integer variable square1 and square2
//               4. Create double variable sum
//               5. Prints sum of square1 and square2 on console using + and cout command
// Learn terms : 1. integer variable
//               2. cin
//               3. cout
//               4. double variable
//               5. operator + and * and ( )
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Please, put two integer number from keyboard!" << endl;
	int nb1,nb2;
	cin>>nb1>>nb2;
	int square1,square2;
	square1 = nb1*nb1;
	square2 = nb2*nb2;
	double sum=0;
	sum=square1+square2;
	cout << "Summary of ( square of number " << nb1 << ", is: "<< square1<<" ) and ( square of number " << nb2 << ", is: "<< square1 << " ) is : " << sum << endl;
	return 0;
}
