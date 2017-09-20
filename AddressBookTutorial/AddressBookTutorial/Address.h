#pragma once
#include <string>
using namespace std;

class Address
{
public:
	Address();
	Address(int,string, string, string, string);
	string getStreet();
	string getCity();
	string getProvince();
	string getCountry();
	void setStreet(string);
	void setCity(string);
	void setProvince(string);
	void setCountry(string);
	~Address();
private:
	string street;
	string city;
	string province;
	string country;
	int number;

};

