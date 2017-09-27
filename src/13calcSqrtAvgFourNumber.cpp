///============================================================================
// Name        : 13calcSqrtAvgFourNumber.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Calculate square root of average of four number
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
	cout << "Please, put four integer number from keyboard!" << endl;
	int nb1,nb2,nb3,nb4;
	cin>>nb1>>nb2>>nb3>>nb4;
	double avg;
	avg = nb1 + nb2 + nb3 +nb4 ;
	avg = avg / 2;
	double squreRoot;
	squreRoot = sqrt (avg);
	cout << " ( "<< nb1 << " + " << nb2 << " + " << nb3 << " + " << nb4 << " ) / 4 " << " = " << avg ;
	cout << endl;
	cout << "sqrt( " << avg <<" )"<< " = " << squreRoot << endl;
	return 0;
}


