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
	map<string, int> studentMap;
	string tempFirst, tempLast;
	
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
