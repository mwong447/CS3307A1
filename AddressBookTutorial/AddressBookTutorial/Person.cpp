#include "stdafx.h"
#include "Person.h"


Person::Person(Name n, Address a, PhoneNumber p) : name(n), address(a), phone(p)
{

}

Person::~Person()
{
}

Name Person::getName()
{
	return name;
}

Address Person::getAddress()
{
	return address;
}

PhoneNumber Person::getPhoneNumber()
{
	return phone;
}



