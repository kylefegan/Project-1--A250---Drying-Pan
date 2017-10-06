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
	 

	//setStudentInfo


	//getID


	//getNumberOfCourses


	//getCreditsEnrolled
	int getCreditsEnrolled() const;

	//isTuitionPaid


	//isEnrolledInCourse
	

	//getGpa


	//billingAmount
	int billingAmount(double tuitionRate) const;

	//printStudentInfo
	void printStudentInfo() const;

	//printStudentInfo
	void printStudentInfo(double tuition) const;

	//getCoursesEnrolled


	//Destructor


private:
    int studentID;				
    int numberOfCourses;	
    bool tuitionWasPaid;		
    vector<Course> coursesEnrolled; 
};

#endif



