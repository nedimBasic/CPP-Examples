///============================================================================
// Name        : 15calcSqrtSumSquareTwoNumber.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Calculate square root of average of two number
// Learn terms : 1. integer variable
//               2. cin
//               3. cout
//               4. double variable
//               5. operator + and ( )
//               6. function sqrt(),pow()
//============================================================================
#include <math.h>
#include <iostream>
using namespace std;

int main() {
	cout << "Please, put two integer number from keyboard!" << endl;
	int nb1,nb2;
	cin>>nb1>>nb2;
	double sum;
	sum = pow(nb1,2) + pow(nb2,2);
	double squreRoot;
	squreRoot = sqrt (sum);
	cout << "sqr( "<< nb1 << " ) + " <<"sqr( " << nb2 << " ) = " << sum << endl;
	cout << "sqrt( " << sum <<" )"<< " = " << squreRoot << endl;
	return 0;
}
