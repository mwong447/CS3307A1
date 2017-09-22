#pragma once
#include <vector>
#include <iostream>
#include "Person.h"
#include <math.h>
#include <random>
using namespace std;

class Randomizer
{
public:
	Randomizer();
	~Randomizer();
	Name randomName(vector<string>, vector<string>);
	Address randomAddress(vector<int>,vector<string>, vector<string>, vector<string>);
	PhoneNumber randomPhone(vector<int>);
	vector<Person> getAddressBook();
	void addEntry(Person);
private:
	vector<Person> addressBook;
	int randomize(vector<string>);
	int randomizeNumber(vector<int>);

};

