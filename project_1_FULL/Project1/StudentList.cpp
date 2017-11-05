/*
Drying Pan

Ngo, Matthew
Fegan, Kyle
Manning, Tristan
Cortes, Andre

CS A250 - Fall 2017

Project 1
*/

#include "StudentList.h"


// default constructor
StudentList::StudentList()
{
	count = 0;
	first = nullptr;
	last = nullptr;
}

// addStudent
void StudentList::addStudent(Student& object)
{
	Node * current = new Node(object, first);
	first = current;
	count++;
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return count;
}


// printStudentByID
void StudentList::printStudentByID(int idNum, double tuitionRate) const
{
	if (count == 0)
		cerr << "List is empty" << endl;
	else
	{
		Node* current = first;
		bool found = false;
		while (current != nullptr && !found)
		{
			if (current->getStudent().getID() == idNum)
			{
				current->getStudent().printStudentInfo(tuitionRate);
				found = true;
			}
			current = current->getNext();
		}
		if (!found)
			cout << "No student with ID " << idNum << " found in list" << endl;
	}
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& courseNumber) const
{
	if (count == 0) cerr << "List is empty" << endl;
	else
	{
		Node* current = first;
		bool found = false;
		while (current != nullptr)
		{
			if (current->getStudent().isEnrolledInCourse(courseNumber))
			{
				current->getStudent().printStudentInfo();
				if (!found) found = true;
			}
			current = current->getNext();
		}
		if (!found) cout << "No student enrolled in " << courseNumber << endl;
	}
}

// printStudentByName
void StudentList::printStudentByName(const string& lastName) const
{
	if (count == 0)
	{
		cerr << "List is empty" << endl;
	}
	else
	{
		bool found = false;
		Node * current = first;

		while (current != nullptr) 
			// !found not part of condition because possible >1 student with last name
		{
			if (current->getStudent().getLastName() == lastName)
			{
				found = true;
				current->getStudent().printStudentInfo();
			}
			current = current->getNext();
		}
		if (!found)
			cout << "No student with last name " << lastName << " is in the list." << endl;
	}		
}


// printStudentsOnHold
void StudentList::printStudentsOnHold(double tuitionRate) const
{
	if (count == 0)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		bool found = false;
		Node* current = first;
		while (current != nullptr)
		{
			if (!current->getStudent().isTuitionPaid())
			{
				current->getStudent().printStudentInfo();
				cout << "\t Amount Due: $" << current->getStudent().billingAmount(tuitionRate) << endl;
				found = true;
			}
			current = current->getNext();
		}
		if (!found)
		{
			cout << "There are no students on hold." << endl;
		}
	}
}

// printAllStudents
void StudentList::printAllStudents(double tuitionRate) const
{
	if (count == 0) 
		cerr << "List is empty" << endl;
	else
	{
		Node* current = first;
		while (current != nullptr)
		{
			current->getStudent().printStudentInfo(tuitionRate);
			current = current->getNext();
		}
	}
}

// printStudentsToFile



// destroyStudentList
void StudentList::destroyStudentList()
{
	Node  *temp = first;
	while (first != nullptr)
	{
		temp = temp->getNext();
		delete first;
		first = nullptr;
	}
	count = 0;
}


// destructor
StudentList::~StudentList() 
{
	destroyStudentList();
}
