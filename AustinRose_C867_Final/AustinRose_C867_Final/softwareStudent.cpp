#pragma once
#include <iostream>
#include "softwareStudent.h"
using std::cout;


SoftwareStudent::SoftwareStudent()
{
	setDegreeType(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string ID, string fname, string lname, string email, int age, double* days, Degree type)
{
	setDegreeType(SOFTWARE);
}

Degree SoftwareStudent::getDegreeType()
{
	return SOFTWARE;
}

void SoftwareStudent::setDegreeType(Degree d)
{
	this->degreeType = SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
}