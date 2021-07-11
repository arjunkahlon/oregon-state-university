/************************************************
University.h: Definition file for University Class
************************************************/

#include "University.h"



University::University()     //initializes name
{
	name = "Oregon State University";
}

string University::getName()    //returns name
{
	return name;
}

void University::printBuildingAddress()    //prints Building Info
{
	vector<Building>::iterator Building;   //declares iterator to traverse vector
	for (Building = this->bldgs.begin(); Building != this->bldgs.end(); ++Building)
	{
		cout << "\nBuilding Name: " << Building->getName() << endl;
		cout << "Building Address: " << Building->getBuildingAddress() << endl;
		cout << "Building Size: " << Building->getSize() << " sq ft" << endl << endl;
	}
}

void University::printPeople()      //prints info on people
{
	vector<Person*>::iterator person;
	for (person = this->people.begin(); person != this->people.end(); ++person)
	{
		cout << "\nPerson Name: " << (*person)->getName() << endl;
		cout << (*person)->getName() << "'s Age: " << (*person)->getAge() << endl << endl;
	}
}

void University::saveBuilding(const Building& Building)     //stores building in vector
{
	this->bldgs.push_back(Building);     //adds building to end of vector
}

void University::savePerson(Person* person)    //stores person in vector
{
	this->people.push_back(person);    //adds person to end of vector
}

Person* University::findPerson(string s)   //finds specific person in person vector
{
     vector<Person*>::iterator iter;
     for(iter = this->people.begin(); iter != this->people.end(); ++iter)
     {
        if((*iter)->getName() == s)
        {
           return *iter;    //returns Person*
        }
     }
return NULL;
}

University::~University()
{
}

