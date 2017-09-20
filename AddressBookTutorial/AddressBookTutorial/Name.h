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

private:
	string firstName, lastName;
};

