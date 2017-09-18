// AddressBookTutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
	Person p1("Matthew", "Wong");
	cout << p1.firstName << endl;
	cout << p1.lastName;
    return 0;
}

