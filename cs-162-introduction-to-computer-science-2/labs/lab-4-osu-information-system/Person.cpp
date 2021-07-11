/*********************************************************
Person.cpp: This is the definition file for the Person
class.
*********************************************************/

#include "Person.h"



Person::Person(string s, int i)  //constructor
{
	name = s;
	age = i;
}

string Person::getName()    //returns name of person
{
	return name;
}
int Person::getAge()
{
	return age;
}

/*void Person::displayHours(int hours)
{
    cout << "Person worked " << hours << " hours.";
}*/

void Person::do_work()     //overridden in Student and Instructor classes
{
    return;
}

