/***************************************************
Instructor.h: Declaration file for Instructor Class
***************************************************/

#ifndef Instructor_H
#define Instructor_H

#include "Person.h"
class Instructor: public Person
{
private:
	float rating;
//protected:
    //void displayHours(int);
public:
	Instructor(string, int, float);
	float getRating();
	void setRating(float);
	void do_work();
	~Instructor();
};

#endif
