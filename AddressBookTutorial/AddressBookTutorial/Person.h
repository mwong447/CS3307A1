#pragma once
#include "Name.h"
#include "Address.h"
#include "PhoneNumber.h"



class Person
{
public:
	Person(Name, Address, PhoneNumber);
	~Person();
	Name getName();
	Address getAddress();
	PhoneNumber getPhoneNumber();
private:
	Name name;
	Address address;
	PhoneNumber phone;

};

