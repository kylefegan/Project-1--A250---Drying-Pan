#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

class Student: public Person
{
public:

	//Default constructor   
	 Student() : studentID(0), numberOfCourses(0), tuitionWasPaid(false) {}

	//setStudentInfo
	void setStudentInfo(const string& first, const string& last, int idNum, bool paidTuition, vector<Course>& studentClass);

	//getID
	int getID() const;

	//getNumberOfCourses
	int getNumberOfCourses() const;

	//getCreditsEnrolled
	int getCreditsEnrolled() const;

	//isTuitionPaid
	int getNumberOfCourses() const;

	//isEnrolledInCourse
	bool isEnrolledInCourse(const string& course);

	//getGpa


	//billingAmount
	int billingAmount(double tuitionRate) const;

	//printStudentInfo
	void printStudentInfo() const;

	//printStudentInfo
	void printStudentInfo(double tuition) const;

	//getCoursesEnrolled


	//Destructor
	~Student();

private:
    int studentID;				
    int numberOfCourses;	
    bool tuitionWasPaid;		
    vector<Course> coursesEnrolled; 
};

#endif



