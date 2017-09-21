#pragma once

#include <string>
using namespace std;

class Name
{
public:
	Name(string, string);
	Name();
	~Name();

	string getFirstName();
	string getLastName();
	void setFirstName(string x);
	void setLastName(string y);
	string lastNameToJSON();
	string firstNameToJSON();

private:
	string firstName, lastName;
};

