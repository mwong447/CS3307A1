#pragma once
#include <string>
#include <iostream>
using namespace std;

class PhoneNumber
{
public:
	PhoneNumber(string);
	~PhoneNumber();
	PhoneNumber();
	string getPhoneNumber();
	string PhoneNumberToJSON();

private:
	string areaCode;
	string firstPart;
	string secondPart;

};

