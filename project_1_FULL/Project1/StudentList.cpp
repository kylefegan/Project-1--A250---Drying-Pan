/************************
	FlavorTown

	Ngo, Matthew
	Fegan, Kyle
	Manning, Tristan
	Cortes, Andre

	CS A250 - Fall 2017

	Project 2
*************************/

#include "StudentList.h"


// default constructor
StudentList::StudentList()
{
	studentList = new vector<Student>;
}

// addStudent
void StudentList::addStudent(const Student& newStudent)
{
	studentList->push_back(newStudent);
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return static_cast<int>(studentList->size());
}


// printStudentByID
void StudentList::printStudentByID(int idNum, double tuitionRate) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();
	bool found = false;
	while (iter != iterEnd && !found)
	{
		if(iter->getID() == idNum)
		{
			iter->printStudentInfo(tuitionRate);
			found = true;
		}
		++iter;
	}
	if (!found)
		cout << "No student with ID " << idNum << " found in the list." << endl;
	cout << endl;
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& courseNumber) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();
	bool found = false;

	for (iter; iter != iterEnd; ++iter)
	{
		if (iter->isEnrolledInCourse(courseNumber))
		{
			iter->printStudentInfo();
			if (!found) found = true;
		}
	}
	
	if (!found) cout << "No student enrolled in " << courseNumber << endl;
	cout << endl;
}

// printStudentByName
void StudentList::printStudentByName(const string& lastName) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();
	bool found = false;

	for (iter; iter != iterEnd; ++iter)
	{
		if (iter->getLastName() == lastName)
			{
				found = true;
				iter->printStudentInfo();
			}
	}
	if (!found)
		cout << "No student with last name " << lastName << " is in the list." << endl;		
	cout << endl;
}


// printStudentsOnHold
void StudentList::printStudentsOnHold(double tuitionRate) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();
	bool found = false;
	//!found not part of condition because possibile that more than one student same last name
	for (iter; iter != iterEnd; ++iter)
	{
		if (!iter->isTuitionPaid())
		{
			iter->printStudentInfo();
			cout << "\t Amount Due: $" << iter->billingAmount(tuitionRate) << endl;
			found = true;
		}
	}
	if (!found)
	cout << "There are no students on hold." << endl;
	cout << endl;
}

// printAllStudents
void StudentList::printAllStudents(double tuitionRate) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();

	for (iter; iter != iterEnd; ++iter)
	{
		iter->printStudentInfo(tuitionRate);
	}
}

// printStudentsToFile
void StudentList::printStudentsToFile(ofstream& outp, double tuitionRate) const
{
	auto iter = studentList->cbegin();
	auto iterEnd = studentList->cend();

	for (iter; iter != iterEnd; ++iter)
	{
		iter->printStudentInfoToFile(outp, tuitionRate);
	}
	cout << endl;
}


// destroyStudentList
void StudentList::destroyStudentList()
{
	delete studentList;
}


// destructor
StudentList::~StudentList() 
{
	destroyStudentList();
}

