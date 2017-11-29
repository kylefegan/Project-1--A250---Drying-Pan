/************************
	FlavorTown

	Ngo, Matthew
	Fegan, Kyle
	Manning, Tristan
	Cortes, Andre

	CS A250 - Fall 2017

	Project 2
*************************/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StudentList
{
public:

	// default constructor
	StudentList();

	// addStudent
	void addStudent(const Student& object);

	// getNoOfStudents
	int getNoOfStudents() const;

	// printStudentByID
	void printStudentByID(int idNum, double tuitionRate) const;

	// printStudentsByCourse
	void printStudentsByCourse(const string& courseNumber) const;

	// printStudentByName
	void printStudentByName(const string& lastName) const;

	// printStudentsOnHold
	void printStudentsOnHold(double tuitionRate) const;

	// printAllStudents
	void printAllStudents(double tuitionRate) const;
	
	//printStudentsToFile
	void printStudentsToFile(ofstream& outp, double tuitionRate) const;

	// destroyStudentList
	void destroyStudentList();

	// destructor
	~StudentList();

protected:
	vector<Student> * studentList; //pointer named studentList that will point to an STL vector of Student objects
};

#endif

