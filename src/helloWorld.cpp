//============================================================================
// Name        : helloWorld.cpp
// Author      : Nedim Basic
// Version     :
// Copyright   : All rights are reserved
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
    int i;
    string broj;
    char buffer[100];
    getline(cin, broj);
    cout<<"---------"<<endl;
    //cin>>i;
    i=stringToInt(buffer);
    cout<<"broj je" << i;
//   tochar(i, buffer);
//   cout<<"karakter je "<<buffer;
   return 0;
}
