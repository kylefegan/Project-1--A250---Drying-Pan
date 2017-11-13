/************************
	Drying Pan

	Ngo, Matthew
	Fegan, Kyle
	Manning, Tristan
	Cortes, Andre

	CS A250 - Fall 2017

	Project 1
*************************/

#include "Student.h"

#include <iostream>
#include <string>
#include <vector>

//default constructor
Student::Student()
{
	studentID = 0;
	numberOfCourses = 0;
	tuitionWasPaid = false;
}

// setStudentInfo
void Student::setStudentInfo(const string& first, const string& last, int idNum, bool paidTuition, const vector<Course>& studentClass)
{
	setName(first, last);
	studentID = idNum;
	tuitionWasPaid = paidTuition;
	coursesEnrolled = studentClass;
	//uses size to determine number of courses
	numberOfCourses = static_cast<int>(studentClass.size());
}
// getID
int Student::getID() const
{
	return studentID;
}

// getNumberOfCourses
int Student::getNumberOfCourses() const
{
	return numberOfCourses;
}

// getCreditsEnrolled
int Student::getCreditsEnrolled() const
{
	int credits = 0;
	//iterates through vector <Course> coursesEnrolled
	for (auto currentCourse : coursesEnrolled)
	{
		//getCourseCredits() from Course class
		credits += currentCourse.getCourseCredits();
	}
	return credits;
}

// isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

// isEnrolledInCourse
bool Student::isEnrolledInCourse(const string& course)
{
	for (auto currentCourse : coursesEnrolled)
	{
		if (currentCourse.getCourseNumber() == course)
			return true;
	}
	return false;
}

// getGpa
double Student::getGpa() const
{
	char grades;
	double gPA = 0;
	double count = 0;
	for (auto currentCourse : coursesEnrolled)
	{
		grades = currentCourse.getCourseGrade();
		switch (grades)
		{
		case 'A':
			gPA += 4.0 * currentCourse.getCourseCredits();
			break;
		case 'B':
			gPA += 3.0 * currentCourse.getCourseCredits();
			break;
		case 'C':
			gPA += 2.0 * currentCourse.getCourseCredits();
			break;
		case 'D':
			gPA += 1.0 * currentCourse.getCourseCredits();
			break;
		}
		count++;
	}

	return gPA / getCreditsEnrolled();
}

// billingAmount
double Student::billingAmount(double tuitionRate) const
{
	return tuitionRate * getCreditsEnrolled();
}

// printStudentInfo
void Student::printStudentInfo() const
{
	cout << getID() << " -- ";
	printName();
}

// printStudentInfo (overloaded)
void Student::printStudentInfo(double tuition) const
{
	//Name
	cout << "Student Name: ";
	printName();
	cout << endl;

	//ID & Enrolled Courses
	cout << "Student ID: " << getID() << endl;
	cout << "Number of courses enrolled: " << getNumberOfCourses() << endl << endl;

	//Course List
	cout << "Course No  Course Name  Credits Grade" << endl;
	//No need for setw as the header is constant
	for (auto currentCourse : coursesEnrolled)
	{
		currentCourse.printCourseInfo(isTuitionPaid()); //coursesEnrolled
	}
	cout << endl;

	//Credit Hours & GPA
	cout << "Total number of credit hours: " << getCreditsEnrolled() << endl;
	if (isTuitionPaid()) cout << "Current Term GPA: " << getGpa() << endl;
	else
	{
		cout << "*** Grades are being held for not paying the tuition. ***" << endl;
		cout << "Amount Due: $" << billingAmount(tuition) << endl;
	}

	//Footer
	cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;
}

// getCoursesEnrolled
vector<Course> Student::getCoursesEnrolled()
{
	return coursesEnrolled;
}

//same as printStudentInfo but cout->out, no print funcs available
void Student::printStudentInfoToFile(ofstream& out, double tuitionRate)
{
	//Name
	out << "Student Name: ";
		//"out" version of	  printName();
		//changed lastName and firstName to "protected:" in Person.h for child accessability, check if correct
	out << lastName << ", " << firstName << endl;
	out << endl;

	//ID & Enrolled Courses
	out << "Student ID: " << getID() << endl;
	out << "Number of courses enrolled: " << getNumberOfCourses() << endl << endl;

	//Course List
	out << "Course No  Course Name  Credits Grade" << endl;

	for (auto currentCourse : coursesEnrolled)
	{
			//"out" version of	  currentCourse.printCourseInfo(isTuitionPaid());
			//courseNo, courseName, courseCredits, courseGrade changed to get...() funcs
		out << left << setw(11) << currentCourse.getCourseNumber() << setw(17) << currentCourse.getCourseName() << currentCourse.getCourseCredits();
		if (tuitionWasPaid)
			out << right << setw(7) << currentCourse.getCourseGrade() << endl;
		else
			out << right << setw(7) << "***" << endl;
	}
	out << endl;

	//Credit Hours & GPA
	out << fixed<< setprecision(2);
	out << "Total number of credit hours: " << getCreditsEnrolled() << endl;
	if (isTuitionPaid()) out << "Current Term GPA: " << getGpa() << endl;
	else
	{
		out << "*** Grades are being held for not paying the tuition. ***" << endl;
		out << "Amount Due: $" << billingAmount(tuitionRate) << endl;
	}

	//Footer
	out << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;
}

// destructor
Student::~Student() {}
