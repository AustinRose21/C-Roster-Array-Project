#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student
{
public:
	NetworkStudent();
	NetworkStudent(
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

	~NetworkStudent();
};
