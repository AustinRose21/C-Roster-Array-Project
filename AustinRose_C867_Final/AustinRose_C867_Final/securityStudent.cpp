#pragma once
#include <iostream>
#include "securityStudent.h"
using std::cout;


SecurityStudent::SecurityStudent()
{
	setDegreeType(SECURITY);
}

SecurityStudent::SecurityStudent(string ID, string fname, string lname, string email, int age, double* days, Degree type)
{
	setDegreeType(SECURITY);
}

Degree SecurityStudent::getDegreeType()
{
	return SECURITY;
}

void SecurityStudent::setDegreeType(Degree d)
{
	this->degreeType = SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;
}