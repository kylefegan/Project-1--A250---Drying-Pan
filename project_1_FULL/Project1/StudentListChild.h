/************************
FlavorTown

Ngo, Matthew
Fegan, Kyle
Manning, Tristan
Cortes, Andre

CS A250 - Fall 2017

Project 2
*************************/

#ifndef STUDENTLISTCHILD_H
#define STUDENTLISTCHILD_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "StudentList.h"

using namespace std;

class StudentListChild : public StudentList
{
public:

	// default constructor
	StudentListChild();

	//printStudentsInOrder
	void printStudentsInOrder() const;

	// destructor
	~StudentListChild();
};


#endif
