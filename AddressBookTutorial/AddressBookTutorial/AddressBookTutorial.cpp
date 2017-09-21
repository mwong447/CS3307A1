// AddressBookTutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "Randomizer.h"

using namespace std;

int main()
{
	vector<string> firstNames;
	vector<string> lastNames;

	firstNames.push_back("Matthew");
	firstNames.push_back("Noah");
	firstNames.push_back("James");
	firstNames.push_back("John");
	firstNames.push_back("Robert");
	firstNames.push_back("William");

	lastNames.push_back("Wang");
	lastNames.push_back("Zhang");
	lastNames.push_back("Lee");
	lastNames.push_back("Smith");
	lastNames.push_back("Garcia");
	lastNames.push_back("Rossi");


	Randomizer rand(15, firstNames, lastNames);
	for (int i = 0; i < 15; i++)
	{
	cout << rand.addressBook[i].getFirstName() << endl;
	}
	

	


	return 0;
}

