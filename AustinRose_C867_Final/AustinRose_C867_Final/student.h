#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student {

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double days[3];
	Degree degreeType;  //enumerated value

public:
	const static int daysArraySize = 3;
	Student();
	Student(string ID, string fname, string lname, string email, int age, double days[3], Degree type);


	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	double* getDays();
	virtual Degree getDegreeType()=0;
	

	//setters
	void setStudentID(string ID);
	void setFirstName(string fname);
	void setLastName(string lname);
	void setEmailAddress(string email);
	void setAge(int age);
	void setDays(double days[3]);
    virtual void setDegreeType(Degree d) = 0;
	virtual void print() = 0;

	~Student();


};
