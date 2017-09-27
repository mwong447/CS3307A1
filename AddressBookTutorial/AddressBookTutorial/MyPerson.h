#pragma once
#include <Wt/WResource>
#include <Wt/Http/Response>
#include "Person.h"
#include <string>
#include <iostream>
#include <vector>

using namespace Wt;
using namespace Wt::Http;
extern int x;
extern std::vector<int> v;
extern std::vector<Person> people;

class MyPerson : public WResource
{
public:
	MyPerson();
	virtual ~MyPerson();
protected:
	virtual void handleRequest(const Request &request, Response & response);
};

