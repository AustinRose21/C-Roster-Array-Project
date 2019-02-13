#pragma once
#include <string>
#include <iostream>
#include "student.h"

using std::string;

const int numStudents = 5;


const string studentData[numStudents] =
{
"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Austin,Rose,arose63@wgu.edu,24,20,15,30,SOFTWARE"
};

class Roster {
public:
	int lastIndex; //index the last student in roster, records entries
	int capacity; // max size of the roster
	Student** students; //array of pointers? should this be classRosterArray??? ***
	Roster(); //empty constructor
	Roster(int capacity); //full constructor, can set initial capacity by using this
	void parseAdd(); //seperates string in studentData, based on comma, into seperate pieces PRODUCES STUDENT OBJECT AND ADDS TO ROSTER
	void print_All(); //prints all student data using each student print() method
	bool remove(string studentID); //removes student based on ID field
	void printAverageDays(string studentID); //prints average # of days to complete based on studentID
	void printInvalidEmails(); //searches every student in studentData and prints invalid emails
	void printByDegreeType(Degree d); //prints all students of type
	~Roster(); //destructor
};
