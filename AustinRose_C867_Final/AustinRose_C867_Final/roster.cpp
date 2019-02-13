#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"

using std::string;
using std::cout;
using std::cerr;



Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1; //empty last index, as 0 is a valid starting index we use -1
	this->students = nullptr; //classRosterArray?
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->students = new Student*[capacity];
}

void Roster::parseAdd()
{
	for (int i = 0; i < numStudents; i++) {
		int len = studentData[i].length();
		char lastChar = studentData[i][len - 1];
		//cout << lastChar << ' ';
		if (lastChar == 'Y') {
			students[i] = new SecurityStudent();
			students[i]->setDegreeType(SECURITY);
		}
		else if (lastChar == 'E') {
			students[i] = new SoftwareStudent();
			students[i]->setDegreeType(SOFTWARE);
		}
		else if (lastChar == 'K') {
			students[i] = new NetworkStudent();
			students[i]->setDegreeType(NETWORKING);
		}



		//parsing each line based on comma
		//read studentID
		int rhs = studentData[i].find(",");
		cout << studentData[i].substr(0, rhs) << ' ';
		students[i]->setStudentID(studentData[i].substr(0, rhs));

		//read fname
		int lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		cout << studentData[i].substr(lhs, rhs - lhs) << ' ';
		students[i]->setFirstName(studentData[i].substr(lhs, rhs - lhs));

		//read lname
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		cout << studentData[i].substr(lhs, rhs - lhs) << ' ';
		students[i]->setLastName(studentData[i].substr(lhs, rhs - lhs));

		//read email
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		cout << studentData[i].substr(lhs, rhs - lhs) << ' ';
		students[i]->setEmailAddress(studentData[i].substr(lhs, rhs - lhs));

		//read age
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		cout << studentData[i].substr(lhs, rhs - lhs) << ' ';
		students[i]->setAge(stoi(studentData[i].substr(lhs, rhs - lhs)));

		double * darray = new double[3];
		//read day 1
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		cout << studentData[i].substr(lhs, rhs - lhs) << ' ';
		darray[0] = stod(studentData[i].substr(lhs, rhs - lhs));

		//read day 2
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		cout << studentData[i].substr(lhs, rhs - lhs) << ' ';
		darray[1] = stod(studentData[i].substr(lhs, rhs - lhs));

		//read day 3
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		cout << studentData[i].substr(lhs, rhs - lhs) << ' ';
		darray[2] = stod(studentData[i].substr(lhs, rhs - lhs));

		//set the days?
		students[lastIndex]->setDays(darray);


	}


	
}



	

	


void Roster::print_All()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->students)[i]->print();
}


bool Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getStudentID() == studentID) // student found
		{
			found = true;
			delete this->students[i]; //deletes book from roster

			this->students[i] = this->students[lastIndex];
			lastIndex--; //decrement lastIndex
		}
	}
	return found;
}


void Roster::printAverageDays(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getStudentID() == studentID) //student found
		{
			found = true;
			double* d = students[i]->getDays();
			cout << "Average days to complete " << studentID << " is " << (d[0] + d[1] + d[2]) / 3 << "\n";
		}
	}
	if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
	cout << "Showing invalid email addresses:\n";
	for (int i = 0; i <= lastIndex; i++)
	{
		string email = students[i]->getEmailAddress();
		bool isValid = false; //assuming all are bad if checks don't go through

		size_t found = email.find("@");
		if (found != string::npos) {
			found = email.find(".");
			if (found != string::npos) {
				found = email.find(" ");
				if (found == string::npos) {
					isValid = true;
				}
			}
		}
		if (!isValid) {
			cout << email << " is not a valid email address \n";
		}
	}
}

void Roster::printByDegreeType(Degree d)
{
	cout << "Showing students of same degree type " << degreeTypeStrings[d] << "\n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->students[i]->getDegreeType() == d) this->students[i]->print();
	}
}


Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete this->students[i];
	}
	delete this;
}



int main()
{
	cout << "Scripting and Programming - Applications (C867) \n";
	cout << "Using VisualStudio, coded in C++ \n";
	cout << "Austin Rose \n";
	cout << "Student ID:000779381";


	Roster * classRoster = new Roster(numStudents); //main roster
	cout << "Parsing data, adding students...";
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseAdd();
	}
	cout << "Displaying all students:\n";
	classRoster->print_All(); // show all students in the roster

	classRoster->printInvalidEmails(); //prints out invalid email addresses
	
	classRoster->printAverageDays("A3"); //prints average days of specified studentID

	classRoster->printByDegreeType(SOFTWARE); //printing software students

	cout << "Removing A3:\n"; //remove student with supplied ID
	if (classRoster->remove("A3")) classRoster->print_All();
	else cout << "Student not found!\n";

	system("pause");
}








