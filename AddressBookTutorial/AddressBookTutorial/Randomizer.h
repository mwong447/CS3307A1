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
	int randomize(vector<string>);
	vector<Name> addressBook;

};

