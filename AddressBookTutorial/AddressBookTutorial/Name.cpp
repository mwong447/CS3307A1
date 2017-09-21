#include "stdafx.h"
#include "Name.h"


Name::Name(string first, string second)
{
	firstName = first;
	lastName = second;
}

Name::Name()
{
	firstName = "";
	lastName = "";
}

Name::~Name()
{

}

string Name::getFirstName()
{
	return firstName;
}

string Name::getLastName()
{
	return lastName;
}

void Name::setFirstName(string x)
{
	firstName = x;
}

void Name::setLastName(string y)
{
	lastName = y;
}

string Name::lastNameToJSON()
{
	return "\"lastname\"" + string(":  ") + string("\"") + getLastName() + string("\"");
}

string Name::firstNameToJSON()
{
	return "\"firstname\"" + string(":  ") + string("\"") + getFirstName() + string("\"");
}
