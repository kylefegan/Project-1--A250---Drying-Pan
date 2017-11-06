/*
Drying Pan

Ngo, Matthew
Fegan, Kyle
Manning, Tristan
Cortes, Andre

CS A250 - Fall 2017

Project 1
*/

#include "InputHandler.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void displayMenu();
void processChoice(const StudentList& studentList, double tuitionRate);

int main()
{
	StudentList studentList;
	double tuitionRate = 0.0;

	readStudentData(studentList, tuitionRate);
	displayMenu();
	processChoice(studentList, tuitionRate);

	cout << endl;
	system("Pause");
	return 0;
}

void displayMenu()
{
	cout << "\n*** MAIN MENU ***\n";
	cout << "\nSelect one of the following:\n\n";
	cout << "    1: Print all students" << endl;
	cout << "    2: Print student information" << endl;
	cout << "    3: Search student by last name" << endl;
	cout << "    4: Print students by course" << endl;
	cout << "    5: Print students on hold" << endl;
	cout << "    6: Print students to file" << endl;

}

void processChoice(const StudentList& studentList, double tuitionRate)
{
	int choice = 0, id = 0;
	string courseNumber, lastName;

	cout << "\nEnter your choice: ";
	cin >> choice; 
	cout << endl;

	cout << fixed << showpoint << setprecision(2); 

	do
	{
		string fName, lName;
		ofstream outp;
		int ssn = 0;
		double donation = 0.0;
		if (choice == 7)
			cout << "Thank you for using the OCC Gradebook. Good bye!" << endl;
		else
		{
			switch(choice)
			{
			
			
				// Print all students
			case 1:
				if (studentList.getNoOfStudents() > 0)studentList.printAllStudents(tuitionRate);
				else cout << "There are no student in the list " << endl;
				break;

				// Print student information
			case 2:
				cout << "Please enter student's ID: ";
				cin >> id;
				cout << endl;

				if (studentList.getNoOfStudents() > 0)studentList.printAllStudents(tuitionRate);
				else cout << "There are no student in the list " << endl;

				break;

				// Search student by last name
			case 3:
				cout << "Please enter the student's last name: ";
				cin >> lastName;
				cout << endl;

				if (studentList.getNoOfStudents() > 0)studentList.printAllStudents(tuitionRate);
				else cout << "There are no student in the list " << endl;

				break;

				// Print students by course 
			case 4:
				cout << "Please enter the course number: ";
				cin >> courseNumber;
				cout << endl;

				if (studentList.getNoOfStudents() > 0)studentList.printAllStudents(tuitionRate);
				else cout << "There are no student in the list " << endl;

				break;

				// Print students on hold
			case 5:
				if (studentList.getNoOfStudents() > 0)studentList.printAllStudents(tuitionRate);
				else cout << "There are no student in the list " << endl;

				break;

				// Print students to file
			case 6:
				if (studentList.getNoOfStudents() > 0)studentList.printStudentsToFile(outp, tuitionRate);
				else cout << "There are no student in the list " << endl;
				
			break;

			// Incorrect selection
			default: 
				cout << "\nSorry. That is not a selection." << endl;

			break;
			}
		}
	
		
		system("Pause");
		displayMenu();

		cout << "\nEnter your choice: ";
		cin >> choice;
		cout << endl;
	} while (choice != 7);

}
