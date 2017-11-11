/************************
	Drying Pan

	Ngo, Matthew
	Fegan, Kyle
	Manning, Tristan
	Cortes, Andre

	CS A250 - Fall 2017

	Project 1
*************************/

#include "Course.h"

// default constructor
Course::Course()
{
	courseGrade = '*';
	courseCredits = 0;
}

// setCourseInfo
void Course::setCourseInfo(const string& newName, const string& newNo, char newGrade, int newCredits)
{
	courseName = newName;
	courseNo = newNo;
	courseGrade = newGrade;
	courseCredits = newCredits;
}

// printCourseInfo
void Course::printCourseInfo(bool printable) const
{
	cout << left << setw(11) << courseNo << setw(17) << courseName << courseCredits;
	if (printable)
		cout << right << setw(7) << courseGrade << endl;
	else
		cout << right << setw(7) << "***" << endl;
}

// getCourseCredits
int Course::getCourseCredits() const
{
	return courseCredits;
}

// getCourseNumber
string Course::getCourseNumber() const
{
	return courseNo;
}

// getCourseName
string Course::getCourseName() const
{
	return courseName;
}

// getCourseGrade
char Course::getCourseGrade() const
{
	return courseGrade;
}

// destructor
Course::~Course(){}

