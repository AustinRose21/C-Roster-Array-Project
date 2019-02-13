#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student
{
public:
	SecurityStudent();
	SecurityStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		double* days,
		Degree degreeType
	);


	Degree getDegreeType();
	void setDegreeType(Degree d);
	void print();

	~SecurityStudent();
};

