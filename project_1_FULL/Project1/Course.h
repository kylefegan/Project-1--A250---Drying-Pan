/*
	Ngo, Matthew
	Fegan, Kyle
	Manning, Tristan
	Cortes, Andre

	CS A250
	September 29, 2017

	Project 1
*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Course
{
public:

	// default constructor
	Course();

	// setCourseInfo
	void setCourseInfo(const string& newName, const string& newNo, char newGrade, int newCredits);

	// printCourseInfo
	void printCourseInfo(bool printable) const;

	// getCourseCredits
	int getCourseCredits() const;

	// getCourseNumber
	string getCourseNumber() const;

	// getCourseName
	string getCourseName() const;

	// getCourseGrade
	char getCourseGrade() const;

	// destructor
	~Course();

private:
    string courseName; 	
    string courseNo; 	
    char courseGrade;	
    int courseCredits;	
};

#endif