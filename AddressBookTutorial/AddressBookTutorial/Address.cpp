#include "stdafx.h"
#include "Address.h"


Address::Address()
{
	street = "";
	city = "";
	province = "";
	country = "";
}

Address::Address(int a,string w, string x, string y, string z)
{
	street = w;
	city = x;
	province = y;
	country = z;
	number = a;
}


Address::~Address()
{
}

string Address::streetToJSON()
{
	return "\"streetaddress\"" + string(":  ") + string("\"") + to_string(getNumber()) + string(" ") + getStreet() +  string("\"");
}

string Address::cityToJSON()
{
	return "\"city\"" + string(":  ") + string("\"") + getCity() + string("\"");
}

string Address::provinceToJSON()
{
	return "\"province\"" + string(":  ") + string("\"") + getProvince() +string("\"");
}

string Address::countryToJSON()
{
	return "\"country\"" + string(":  ") + string("\"") + getCountry() + string("\"");
}

string Address::getStreet()
{
	return street;
}

string Address::getCity()
{
	return city;
}

string Address::getProvince()
{
	return province;
}

string Address::getCountry()
{
	return country;
}

int Address::getNumber()
{
	return number;
}

void Address::setStreet(string x)
{
	street = x;
}

void Address:: setCity(string x)
{
	city = x;
}

void Address::setProvince(string x)
{
	province = x;
}

void Address::setCountry(string x)
{
	country = x;
}

void Address::setNumber(int a)
{
	number = a;
}

string Address::getAddress()
{
	return to_string(number) + string(" ") + getStreet() + string(" ") + getCity() + string(" ") + getProvince() + string(" ") + getCountry();
}