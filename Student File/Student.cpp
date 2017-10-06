#include "Student.h"

#include <iostream>
#include <string>
#include <vector>

// default constructor


// setStudentInfo


// getID


// getNumberOfCourses


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


// isEnrolledInCourse


// getGpa


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


// destructor
