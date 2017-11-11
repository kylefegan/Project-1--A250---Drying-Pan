/************************
	Drying Pan

	Ngo, Matthew
	Fegan, Kyle
	Manning, Tristan
	Cortes, Andre

	CS A250 - Fall 2017

	Project 1
*************************/

#include "Person.h"

//Default and overloaded constructors defined in Person.h

// setName
void Person::setName(const string & first, const string & last)
{
	firstName = first;
	lastName = last;
}

// getLastName
string Person::getLastName() const
{
	return lastName;
}

// getName
void Person::getName(string & first, string & last) const
{
	first = firstName;
	last = lastName;
}

// printName
void Person::printName() const
{
	cout << lastName << ", " << firstName << endl;
}

//destructor
Person::~Person() {}
