#include "stdafx.h"
#include "PhoneNumber.h"
using namespace std;

PhoneNumber::PhoneNumber(string x)
{
	if (x.length() == 10)
	{
		if (!stod(x))
		{
			throw "Invalid Data Entry";
		}

		areaCode = x.substr(0, 3);
		firstPart = x.substr(4, 7);
		secondPart = x.substr(7, 11);

	}

	
}

PhoneNumber::PhoneNumber()
{

}

PhoneNumber::~PhoneNumber()
{
}

string PhoneNumber::getPhoneNumber()
{
	return areaCode + "-" + firstPart + "-" + secondPart;
}
