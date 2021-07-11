/************************************************
University.h: Declaration file for University Class
************************************************/

#ifndef University_H
#define University_H

#include "Building.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class University
{
private:
	string name;
	vector<Building> bldgs;
	vector<Person*> people;
public:
	University();
	void printBuildingAddress();
	void printPeople();
	void saveBuilding(const Building&);
	void savePerson(Person*);
        Person* findPerson(string);
	~University();
	string getName();
};

#endif
