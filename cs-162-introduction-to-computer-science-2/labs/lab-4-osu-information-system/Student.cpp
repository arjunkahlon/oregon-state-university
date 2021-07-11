/************************************************
Student.cpp: Definition file for Student Class
************************************************/

#include "Student.h"



Student::Student(string name, int age, float gpa): Person(name, age)
{
	this->gpa = gpa;    //sets GPA
}

void Student::do_work()    //overrides virtual function
{
       cout << endl << endl << this->getName() << " did " << (rand() % 70 + 1) << " homework hours" << endl << endl;
}

float Student::getGPA() const      //returns GPA
{
	return gpa;
}

Student::~Student()
{
}
