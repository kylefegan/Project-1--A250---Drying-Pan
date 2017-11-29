/************************
FlavorTown

Ngo, Matthew
Fegan, Kyle
Manning, Tristan
Cortes, Andre

CS A250 - Fall 2017

Project 2
*************************/

#include "StudentListChild.h"

// default constructor
StudentListChild::StudentListChild() {}

//printStudentsInOrder
void StudentListChild::printStudentsInOrder() const
{
	//Andre
	
	//Accessing first and last
	//==========================================
	//Declare string tempFirst
	//Declare string tempLast
	//Use Person::getName(tempFirst, tempLast) to  change the values of tempFirst and tempLast;
	//Store tempLast + ", " + tempFirst as the key of the map.
	//Profit
	map<string, int> studentMap;
	string tempFirst, tempLast;
	//Andre
	for (auto i : *studentList)
	{
		i.getName(tempFirst, tempLast);
		studentMap.insert(pair<string, int>(tempLast + ", " + tempFirst, i.getID()));
	}
		
	for (auto i : studentMap)
		cout << i.second << " - " << i.first << endl;
	cout << endl;
}

// destructor
StudentListChild::~StudentListChild() {}
