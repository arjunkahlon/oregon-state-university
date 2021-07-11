/************************************************
Student.h: Declaration file for Student Class
************************************************/

#ifndef Student_H
#define Student_H

#include "Person.h"


class Student: public Person
{
private:
	float gpa;
protected:
    //void displayHours(int);
public:
	Student(string, int, float);
	float getGPA() const;
	void do_work();
	~Student();
};

#endif
