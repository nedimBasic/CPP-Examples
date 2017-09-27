///============================================================================
// Name        : 12calcSqrtAvgTwoNumber.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Calculate square root of average of two number
// Learn terms : 1. integer variable
//               2. cin
//               3. cout
//               4. double variable
//               5. operator + and / and ( )
//               6. function sqrt()
//============================================================================
#include <math.h>
#include <iostream>
using namespace std;

int main() {
	cout << "Please, put two integer number from keyboard!" << endl;
	int nb1,nb2;
	cin>>nb1>>nb2;
	double avg;
	avg = nb1 + nb2;
	avg = avg / 2;
	double squreRoot;
	squreRoot = sqrt (avg);
	cout << " ( "<< nb1 << " + " << nb2 <<" ) / 2 " << " = " << avg << endl;
	cout << "sqrt( " << avg <<" )"<< " = " << squreRoot << endl;
	return 0;
}
