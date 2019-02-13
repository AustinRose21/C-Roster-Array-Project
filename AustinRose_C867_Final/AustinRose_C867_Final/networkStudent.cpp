#pragma once
#include <iostream>
#include "networkStudent.h"
using std::cout;


NetworkStudent::NetworkStudent()
{
	setDegreeType(NETWORKING);
}

NetworkStudent::NetworkStudent(string ID, string fname, string lname, string email, int age, double* days, Degree type)
{
	setDegreeType(NETWORKING);
}

Degree NetworkStudent::getDegreeType()
{
	return NETWORKING;
}

void NetworkStudent::setDegreeType(Degree d)
{
	this->degreeType = NETWORKING;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORKING" << "\n";
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
	delete this;
}
