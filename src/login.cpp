// Name        : login.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Description : Algorithm how to programming login with username and password in C++, Ansi-style
// New terms   : getline(), toupper(), string.size()
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout<<"CPP programming: Example Login"<<endl;
			cout<<"=============================="<<endl;
			cout<<"Please, put your username from keyboard!"<<endl; // prints Please, put your username from keyboard!
			string username;
			getline(cin,username);
			cout<<"-----------------------------"<<endl;
			cout<<"Welcome dear "<<username;
			cout<<"------------------------------"<<endl;
			cout<<"Please, put your password from keyboard!"<<endl; // prints Please, put your password from keyboard!
			string password;
			getline(cin,password);
			int size=password.size();
			cout<<"------------------------------"<<endl;
			cout<<"Would you like to see your password Y/N?"<<endl;
			char response;
			cin>>response;
			if (toupper(response)=='Y') {
				cout<<"Your answer is: "<<response<<"es."<<endl;
				cout<<"Your password is: "<<password;
			}
			else if (toupper(response)=='N') {
				cout<<"Your answer is: "<<response<<"o."<<endl;
				cout<<"Your password is: ";
				     for (int i=1; i<size;i++) cout<<"*";
			}
			else {
				cout<<"Your answer is wrong ."<<endl;
				cout<<"Please, next time choose right answer between Y or N!"<<endl;
			}
	return 0;
}
