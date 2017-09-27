#include "stdafx.h"
#include "MyPerson.h"

using namespace std;

MyPerson::MyPerson()
{
}


MyPerson::~MyPerson()
{
}

void MyPerson::handleRequest(const Request & request, Response & response)
{
	ostream &out = response.out();
	out << "{" << endl;
	out << " \"" << "people" << "\"" << ": [" << endl;
	for (int i = 0; i < people.size(); i++)
	{
		
		out << "\"" << "{  id: " << "\"" << " \"" << i + 1 << "\"" << ",  " << people[i].getName().lastNameToJSON() << "," << people[i].getName().firstNameToJSON() << "}"  << endl;
	}
	out << " ]" << endl;
	out << "}";
}
