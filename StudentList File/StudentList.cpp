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



// addStudent



// getNoOfStudents



// printStudentByID
void StudentList::printStudentByID(int idNum, double tuitionRate) const
{
	if (count == 0)
		cerr << "List is Empty" << endl;
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
			cout << "No student with ID # found in list" << endl;
	}
}


// printStudentsByCourse



// printStudentByName



// printStudentsOnHold



// printAllStudents



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

