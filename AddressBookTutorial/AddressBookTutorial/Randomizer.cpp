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

Address Randomizer::randomAddress(vector<int> digits, vector<string> streets, vector<string> cities, vector<string> provinces)
{
	int randomStreet = randomize(streets);
	int randomCity = randomize(cities);
	int randomProvince = randomize(provinces);
	int streetNumber;
	string stringNumber = "";
	for (int i = 0; i < 3; i++)
	{
		int a = randomizeNumber(digits);
		stringNumber = stringNumber + to_string(a);
	}
	streetNumber = stoi(stringNumber);

	Address a1(streetNumber, streets[randomStreet], cities[randomCity], streets[randomStreet], "Canada");
	return a1;
}
PhoneNumber Randomizer::randomPhone(vector<int> digits)
{
	string s = "";
	int rand;
	int i = 0;
	while (i < 10)
	{
		rand = randomizeNumber(digits);
		if (i == 0 && rand == 0)
		{
			rand = randomizeNumber(digits);
		}

		else if (i == 3 && rand == 0)
		{
			rand = randomizeNumber(digits);
		}
		else
		{
			i++;
			s = s + to_string(digits[rand]);
		}

	}
	

	PhoneNumber p1(s);
	return p1;

}



int Randomizer::randomize(vector<string> a)
{
	random_device random;
	mt19937 engine{ random() };
	uniform_int_distribution<int> dist(0, a.size() - 1);
	return dist(engine);
}

int Randomizer::randomizeNumber(vector<int> a)
{
	random_device random;
	mt19937 engine{ random() };
	uniform_int_distribution<int> dist(0, a.size() - 1);
	return dist(engine);
}
