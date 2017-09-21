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
	int getNumber();
	string getAddress();
	void setStreet(string);
	void setCity(string);
	void setProvince(string);
	void setCountry(string);
	void setNumber(int);
	~Address();
	string streetToJSON();
	string cityToJSON();
	string provinceToJSON();
	string countryToJSON();
	
private:
	string street;
	string city;
	string province;
	string country;
	int number;

};

