/******************************************************
Person.h This is the declaration file for the Person
class
*******************************************************/

#ifndef Person_H
#define Person_H

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Person
{
private:
	string name;
	int age;

protected:
    //virtual void displayHours(int) {return;};

public:
	Person(string, int);
	string getName();
	int getAge();
	virtual void do_work();
};

#endif
