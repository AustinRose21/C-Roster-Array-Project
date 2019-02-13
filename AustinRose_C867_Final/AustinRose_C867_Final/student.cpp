#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

Student::Student()  //empty constructor setting everything to default values
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	double days = days[3]; //New array dynamic creation
	for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
}

Student::Student(string ID, string fname, string lname, string email, int age, double* days, Degree type) //full constructor
{
	this->studentID = ID;
	this->firstName = fname;
	this->lastName = lname;
	this->emailAddress = email;
	this->age = age;
	this->days = new double[daysArraySize];
	for (int i = 0; i < 3; i++) this->days[i] = days[i];
}

//getters
string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

double* Student::getDays()
{
	return days;
}

Degree Student::getDegreeType()
{
	return degreeType;
}


//setters
void Student::setStudentID(string ID)
{
	this->studentID = ID;
}

void Student::setFirstName(string fname)
{
	this->firstName = fname;
}

void Student::setLastName(string lname)
{
	this->lastName = lname;
}

void Student::setEmailAddress(string email)
{
	this->emailAddress = email;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDays(double* days[])
{
	if (this->days != nullptr) {
		delete[] this->days;
		this->days = nullptr;
	}
	this->days = new double[daysArraySize];
	for (int i = 0; i < 3; i++)
		this->days[i] = days[i];
}

void Student::print()
{
	cout << left << setw(2) << studentID;
	cout << left << setw(15) << firstName;
	cout << left << setw(15) << lastName;
	cout << left << setw(25) << emailAddress;
	cout << left << setw(2) << age;
	cout << left << setw(5) << days[0];
	cout << left << setw(5) << days[1];
	cout << left << setw(5) << days[2];
}

Student::~Student()
{
	if (days != nullptr) {
		delete[] days;
		days = nullptr;
	}
}