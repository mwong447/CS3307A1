#include "stdafx.h"
#include "Randomizer.h"
using namespace std;


Randomizer::Randomizer()
{
}

Randomizer::Randomizer(int x,vector<string> y, vector<string> z)
{
	for (int i = 0; i < x; i++)
	{
		addressBook.push_back(randomName(y, z));
	}
}



Randomizer::~Randomizer()
{
}

Name Randomizer::randomName(vector<string> firstNames, vector<string> lastNames)
{

	int firstRandom = randomize(firstNames);
	int secondRandom = randomize(lastNames);
	Name n1(firstNames[firstRandom], lastNames[secondRandom]);
	return n1;
}

int Randomizer::randomize(vector<string> a)
{
	random_device random;
	mt19937 engine{ random() };
	uniform_int_distribution<int> dist(0, a.size() - 1);
	return dist(engine);
}
