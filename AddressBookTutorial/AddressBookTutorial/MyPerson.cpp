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
	string s = request.path();
	string y = request.pathInfo();
	ostream &out = response.out();	
	if (s.compare("/person") == 0 && y.length() == 0)
	{
		out << "  {" << endl;
		out << "    \"" << "people" << "\"" << ": [" << endl;
		for (int i = 0; i < people.size(); i++)
		{
			out << "      {" << " \"" << "id" << "\"" << ":" << " \"" << i + 1 << "\"" << ", " << people[i].getName().lastNameToJSON() << ", " << people[i].getName().firstNameToJSON() << " }," << endl;
		}
		out << "    ]" << endl;
		out << "  }";
	}

	else
	{
		y.erase(0, 1);
		out << "  {" << endl;
		out << "    \"" << "id" << "\"" << ":  " << "\"" << stoi(y) << "\"," << endl;
		try
		{
			out << "    " << people.at(stoi(y)-1).getName().lastNameToJSON() << "," << endl;
			out << "    " << people.at(stoi(y)-1).getName().firstNameToJSON() << "," << endl;
			out << "    " << people.at(stoi(y)-1).getAddress().streetToJSON() << "," << endl;
			out << "    " << people.at(stoi(y)-1).getAddress().cityToJSON() << "," << endl;
			out << "    " << people.at(stoi(y)-1).getAddress().provinceToJSON() << "," << endl;
			out << "    " << people.at(stoi(y)-1).getAddress().countryToJSON() << "," << endl;
			out << "    " << people.at(stoi(y)-1).getPhoneNumber().PhoneNumberToJSON() << "," << endl;
			out << "  }" << endl;
		}
		catch (out_of_range& e)
		{
			out << "    Out of Range!" << endl;
			out << "  }" << endl;
		}
	}
}
