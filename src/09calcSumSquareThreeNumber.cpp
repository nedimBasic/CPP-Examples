///============================================================================
// Name        : 09calcSumSquareThreeNumber.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               1. Create three integer variable with name nb1 and nb2 and nb3
//               2. Read three integer number from keyboard using cin
//               3. Create three integer variable square1 and square2 and square3
//               4. Create double variable sum
//               5. Prints sum of square1 and square2 and square3 on console using + and cout command
// Learn terms : 1. integer variable
//               2. cin
//               3. cout
//               4. double variable
//               5. operator + and * and ( )
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Please, put three integer number from keyboard!" << endl;
	int nb1,nb2,nb3;
	cin>>nb1>>nb2>>nb3;
	int square1,square2,square3;
	square1 = nb1*nb1;
	square2 = nb2*nb2;
	square3 = nb3*nb3;
	double sum=0;
	sum=square1+square2+square3;
	cout << sum << " = " << square1 << " + " << square2 << " + " << square3 << endl;
	return 0;
}
