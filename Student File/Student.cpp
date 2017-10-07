#include "Student.h"

#include <iostream>
#include <string>
#include <vector>

// default constructor


// setStudentInfo
void Student::setStudentInfo(const string& first, const string& last, int idNum, bool paidTuition, vector<Course>& studentClass)
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
	int credits;
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
	for (size_t i = 0; i < coursesEnrolled.size(); i++)
	{
		if (coursesEnrolled[i].getCourseNumber() == course)
			return true;
	}
	return false;
}

// getGpa
double Student::getGpa(vector<Course> object) const
{
	for (size_t i = 0; i < object.size; i++)
	{
		
	}
}

// billingAmount
int Student::billingAmount(double tuitionRate) const
{
	return tuitionRate*getCreditsEnrolled();
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
  coursesEnrolled.printCourseInfo();
  cout << endl;
  
  //Credit Hours & GPA
  cout << "Total number of credit hours: " << getCreditsEnrolled() << endl;
  if (isTuitionPaid) cout << "Current Term GPA: " << getGpa() << endl;
  else
  {
    cout << "*** Grades are being held for not paying the tuition. ***" << endl;
    cout << "Amount Due: $" << tuition << endl;
  }
  
  //Footer
  cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;
}

// getCoursesEnrolled
vector<Course> Student::getCoursesEnrolled()
{
	return coursesEnrolled;
}

// destructor
Student::~Student() {}
