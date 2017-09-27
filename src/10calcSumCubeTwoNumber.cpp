///============================================================================
// Name        : 10calcSumCubeTwoNumber.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               1. Create two integer variable with name nb1 and nb2
//               2. Read two integer number from keyboard using cin
//               3. Create two integer variable cube1 and cube2
//               4. Create double variable sum
//               5. Prints sum of cube1 and cube2 on console using + and cout command
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
	int cube1,cube2;
	cube1 = nb1*nb1*nb1;
	cube2 = nb2*nb2*nb2;
	double sum=0;
	sum=cube1+cube2;
	cout <<sum << " = " << cube1 << " + " << cube1 << endl;
	return 0;
}
