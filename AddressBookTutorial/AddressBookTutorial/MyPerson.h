#pragma once
#include <Wt/WResource>

using namespace Wt;
using namespace Wt::Http;

class MyPerson
{
public:
	MyPerson();
	virtual ~MyPerson();
protected:
	virtual void handleRequest(const Request &request, Response & response);
};

