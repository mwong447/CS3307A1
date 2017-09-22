// AddressBookTutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "Randomizer.h"
#include <Wt\WApplication>
#include <Wt\WBreak>
#include <Wt\WContainerWidget>
#include <Wt\WLineEdit>
#include <Wt\WPushButton>
#include <Wt\WText>
#include <Wt\WTable>
#include <Wt\WString>

using namespace Wt;



class AddressBookTutorial :public WApplication
{
public:
	AddressBookTutorial(const WEnvironment& env);

private:
	WLineEdit *nameEdit_;
	WText *greeting_;
	WText *number_;
	WTable *table;
	void message();
	void clear();
	void generate();
	Randomizer r;
	bool success;
	int getNumber(string);
	int rand = 0;


	
};

void AddressBookTutorial::clear()
{
	for (int i = 1; i < rand ; i++)
	{
		table->elementAt(i, 0)->clear();
		table->elementAt(i, 1)->clear();
		table->elementAt(i, 2)->clear();
		table->elementAt(i, 3)->clear();
		table->elementAt(i, 4)->clear();
		table->elementAt(i, 5)->clear();
		table->elementAt(i, 6)->clear();

	}
}

void AddressBookTutorial::generate()
{

	//Initial set up
	vector<string> firstNames;
	vector<string> lastNames;
	vector<string> cities;
	vector<string> streets;
	vector<string> provinces;
	vector<int> digits;
	vector<Person> addressBook;
	for (int i = 0; i < 10; i++)
	{
		digits.push_back(i);
	}
	//Setting up static vector lists for the address book
	firstNames.push_back("Matthew");
	firstNames.push_back("Isabella");
	firstNames.push_back("Sophie");
	firstNames.push_back("John");
	firstNames.push_back("Robert");
	firstNames.push_back("William");
	firstNames.push_back("Oliver");
	firstNames.push_back("Ava");
	firstNames.push_back("Victoria");
	firstNames.push_back("Jessica");

	lastNames.push_back("Wang");
	lastNames.push_back("Zhang");
	lastNames.push_back("Lee");
	lastNames.push_back("Smith");
	lastNames.push_back("Garcia");
	lastNames.push_back("Rossi");
	lastNames.push_back("Muller");
	lastNames.push_back("Taylor");
	lastNames.push_back("Wood");
	lastNames.push_back("Stewart");

	provinces.push_back("Ontario");
	provinces.push_back("British Columbia");
	provinces.push_back("Manitoba");
	provinces.push_back("Saskatchewan");
	provinces.push_back("Prince Edward Island");
	provinces.push_back("New Brunswick");
	provinces.push_back("Newfoundland");
	provinces.push_back("Alberta");
	provinces.push_back("Nova Scotia");
	provinces.push_back("Quebec");

	cities.push_back("Kanata");
	cities.push_back("Robertsonville");
	cities.push_back("Beaver");
	cities.push_back("Stayner");
	cities.push_back("Mont Tremblant");
	cities.push_back("Hercules");
	cities.push_back("Newcastle");
	cities.push_back("Canuck");
	cities.push_back("Baden");
	cities.push_back("Gaspe");

	streets.push_back("West Common Wood");
	streets.push_back("North Windridge Street");
	streets.push_back("South Waldeberg Grove");
	streets.push_back("South Winburn Mount");
	streets.push_back("Old Killam Hill");
	streets.push_back("North Ravine Forest Grove");
	streets.push_back("Hillside View Plaza");
	streets.push_back("Southeast Volk Terrace");
	streets.push_back("North Marmion Academy Lawn");
	streets.push_back("South Hamstrom Road");

	if (rand > 0)
	{
		for (int i = 1; i < rand + 1; i++)
		{
			table->elementAt(i, 0)->clear();
			table->elementAt(i, 1)->clear();
			table->elementAt(i, 2)->clear();
			table->elementAt(i, 3)->clear();
			table->elementAt(i, 4)->clear();
			table->elementAt(i, 5)->clear();
			table->elementAt(i, 6)->clear();

		}
	}
	
	rand = stoi(nameEdit_->text());
	if (rand >= 0)
	{
		for (int i = 1; i < rand + 1; i++)
		{
			Name n1 = r.randomName(firstNames, lastNames);
			Address a1 = r.randomAddress(digits, streets, cities, provinces);
			PhoneNumber p1 = r.randomPhone(digits);
			table->elementAt(i, 0)->addWidget(new WText(n1.getFirstName()));
			table->elementAt(i, 1)->addWidget(new WText(n1.getLastName()));
			table->elementAt(i, 2)->addWidget(new WText(to_string(a1.getNumber()) + string(" ") + a1.getStreet()));
			table->elementAt(i, 3)->addWidget(new WText(a1.getCity()));
			table->elementAt(i, 4)->addWidget(new WText(a1.getProvince()));
			table->elementAt(i, 5)->addWidget(new WText(a1.getCountry()));
			table->elementAt(i, 6)->addWidget(new WText(p1.getPhoneNumber()));
		}
		rand = table->rowCount() - 1;
	}
	rand = stoi(nameEdit_->text());
	
}

void AddressBookTutorial::message()
{
	WString newString = WString(nameEdit_->text());
	string s = newString.toUTF8();
	
	try
	{

		greeting_->setText(to_string(stoi(s)) +string(" number of records generated."));
		number_->setText(to_string(stoi(s)));
	}
	catch (exception& e)
	{
		greeting_->setText(e.what());
	}
	
}

int AddressBookTutorial::getNumber(string x)
{
	return stoi(x);
}


AddressBookTutorial::AddressBookTutorial(const Wt::WEnvironment& env)
	: Wt::WApplication(env)
{



	setTitle("Addressbook");
	
	root()->addWidget(new WText("Enter Number of People you want to generate:"));
	nameEdit_ = new WLineEdit(root());
	nameEdit_->setFocus();
	WPushButton *button = new WPushButton("Generate Records", root());
	button->setMargin(5, Left);
	table = new WTable();
	table->setHeaderCount(1, Orientation::Horizontal);
	table->setWidth(WLength("100%"));
	root()->addWidget(table);
	table->elementAt(0, 0)->addWidget(new WText("First Name"));
	table->elementAt(0, 1)->addWidget(new WText("Last Name"));
	table->elementAt(0, 2)->addWidget(new WText("Street"));
	table->elementAt(0, 3)->addWidget(new WText("City"));
	table->elementAt(0, 4)->addWidget(new WText("Province"));
	table->elementAt(0, 5)->addWidget(new WText("Country"));
	table->elementAt(0, 6)->addWidget(new WText("Phone"));
	
	button->clicked().connect(this, &AddressBookTutorial::message);
	button->clicked().connect(this, &AddressBookTutorial::generate);
	nameEdit_->enterPressed().connect(boost::bind(&AddressBookTutorial::message, this));
	root()->addWidget(new WBreak());
	greeting_ = new WText(root());
	root()->addWidget(new WBreak());
	number_ = new WText(to_string(rand), root());

	
	
	
	

	
}

WApplication *createApplication(const WEnvironment& env)
{
	return new AddressBookTutorial(env);
}


int main(int argc, char **argv)
{
	

	/*  Driver for JSON Methods
	Name n1("Matthew", "Wong");
	cout << n1.firstNameToJSON() << endl;
	cout << n1.lastNameToJSON() << endl;

	Address a1(37, "Elderfield Crescent", "Toronto", "Ontario", "Canada");
	cout << a1.streetToJSON() << endl;
	cout << a1.cityToJSON() << endl;
	cout << a1.provinceToJSON() << endl;
	cout << a1.countryToJSON() << endl;
	PhoneNumber	p1("1234567890");
	cout << p1.PhoneNumberToJSON() << endl;
	*/
	/*
	Name n1 = r.randomName(firstNames, lastNames);
	cout << n1.firstNameToJSON() << endl;
	cout << n1.lastNameToJSON() << endl;

	*/

	
	/*Test for Phone Number randomizer
	

	for (int i = 0; i < 50; i++)
	{
	PhoneNumber p1 = r.randomPhone(digits);
	cout << p1.getPhoneNumber() << endl;
	}
	*/
	

	
	/*
	int random = r.randomizeNumber(digits);
	for (int i = 0; i < 15; i++)
	{
		random = r.randomizeNumber(digits);
		cout << random << endl;
	}
	*/
	/*
	for (int i = 0; i < 50; i++)
	{
		Address a1 = r.randomAddress(digits,streets,cities,provinces);
		Name n1 = r.randomName(firstNames, lastNames);
		PhoneNumber p1 = r.randomPhone(digits);
		Person person(n1, a1, p1);
		addressBook.push_back(person);
		cout << addressBook[i].getName().getFirstName() + addressBook[i].getAddress().getAddress() << endl;
	}	
	
	
	*/
	
	return WRun(argc, argv,&createApplication);


	return 0;
}

