/************************
	Drying Pan

	Ngo, Matthew
	Fegan, Kyle
	Manning, Tristan
	Cortes, Andre

	CS A250 - Fall 2017

	Project 1
*************************/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{
public:

	// Default constructor
	Person() : lastName("N/A"), firstName("N/A") {}

	// Overloaded constructor
	Person(const string& last, const string& first) : lastName(last), firstName(first) {}

	// setName
	void setName(const string & first, const string & last);

	// getLastName
	string getLastName() const;

	// getName
	void getName(string & first, string & last) const;

	// printName
	void printName() const;

	// destructor
	~Person();

//private:
protected:
	string lastName;
	string firstName;
};

#endif
