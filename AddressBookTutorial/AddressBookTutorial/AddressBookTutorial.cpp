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
	WString *number_;
	void greet();

};

void AddressBookTutorial::greet()
{
	WString newString = WString(nameEdit_->text());
	greeting_->setText("Hello there, " + newString);
}

AddressBookTutorial::AddressBookTutorial(const Wt::WEnvironment& env)
	: Wt::WApplication(env)
{

	//Initial set up
	setTitle("Addressbook");
	root()->addWidget(new WText("Enter Number of People you want to generate:"));
	nameEdit_ = new WLineEdit(root());
	nameEdit_->setFocus();
	WPushButton *button = new WPushButton("Generate Records", root());
	button->setMargin(5, Left);

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
	firstNames.push_back("Noah");
	firstNames.push_back("James");
	firstNames.push_back("John");
	firstNames.push_back("Robert");
	firstNames.push_back("William");

	lastNames.push_back("Wang");
	lastNames.push_back("Zhang");
	lastNames.push_back("Lee");
	lastNames.push_back("Smith");
	lastNames.push_back("Garcia");
	lastNames.push_back("Rossi");

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

	Wt::WTable *table = new Wt::WTable();
	root()->addWidget(table);
	root()->addWidget(new WBreak());
	
	greeting_ = new WText(root());
	button->clicked().connect(this, &AddressBookTutorial::greet);
	nameEdit_->enterPressed().connect(boost::bind(&AddressBookTutorial::greet, this));
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
	Randomizer r;
	
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

