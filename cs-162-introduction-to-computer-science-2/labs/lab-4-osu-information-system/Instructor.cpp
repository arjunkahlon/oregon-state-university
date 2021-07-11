/****************************************************
Instructor.cpp: Declaration file for Instructor Class
*****************************************************/

#include "Instructor.h"



Instructor::Instructor(string name, int age, float rating): Person(name, age)
{
	this->rating = rating;     //initializes rating
}

float Instructor::getRating()    //returns teacher rating (Float type)
{
	return rating;
}

void Instructor::setRating(float rating)   //sets rating
{
	this->rating = rating;
}

void Instructor::do_work()
{
	cout << endl << endl << this->getName() << " graded papers for " << rand() % 70 + 1 << " hours" << endl << endl;
}

Instructor::~Instructor()
{
}
