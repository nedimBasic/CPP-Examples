///============================================================================
// Name        : 04writeAverageTwoNumber.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               1. Create two integer variable with name nb1 and nb2
//               2. Read two integer number from keyboard using cin
//               3. Create double  variable with name avg
//               4. Prints average those number on console using / and cout command
// Learn terms : 1. integer variable
//               2. cin
//               3. cout
//               4. double variable
//               5. operator / and ( )
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Please, put two integer number from keyboard!" << endl; // prints Please, put two integer number from keyboard!
	int nb1,nb2;
	cin>>nb1>>nb2;
	double avg;
	avg=double(nb1+nb2)/2;
	cout << "Average of number " << nb1 << " and number " << nb2 << " is : " << avg << endl;
	return 0;
}

/** Solution number 2 because of conversion between type of integer variables and double
 *
#include <iostream>
using namespace std;

int main() {
	cout << "Please, put two integer number from keyboard!" << endl; // prints Please, put two integer number from keyboard!
	int nb1,nb2;
	cin>>nb1>>nb2;
	double avg;
	avg = nb1 + nb2 ;
	avg = avg / 2 ;
	cout << "Average of number " << nb1 << " and number " << nb2 << " is : " << avg << endl;
	return 0;
}
*/
