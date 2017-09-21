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
	Randomizer(int,vector<string>,vector<string>);
	~Randomizer();
	Name randomName(vector<string>, vector<string>);
	Address randomAddress(vector<int>,vector<string>, vector<string>, vector<string>);
	PhoneNumber randomPhone(vector<int>);
	int randomize(vector<string>);
	int randomizeNumber(vector<int>);
	vector<Name> addressBook;

};

