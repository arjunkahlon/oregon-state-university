/************************************************
Building.h: Definition file for Building Class
************************************************/

#include "Building.h"



Building::Building(string n, double s, string b)  //intializes name, size, address
{
	name = n;
	size = s;
	buildingAddress = b;
}

string Building::getName()     //returns name
{
	return name;
}

void Building::setName(string s)    //sets size
{
	name = s;
}
double Building::getSize()   //returns size
{
	return size;
}
void Building::setSize(double d)    //sets size
{
	size = d;
}
string Building::getBuildingAddress() const     //retuns address
{
	return buildingAddress;
}
void Building::setBuildingAddress(string b)   //sets address
{
	buildingAddress = b;
}

Building::~Building()
{
}
