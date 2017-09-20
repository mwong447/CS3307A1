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