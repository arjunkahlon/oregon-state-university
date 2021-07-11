/************************************************
Building.h: Declaration file for Building Class
************************************************/

#ifndef Building_H
#define Building_H

#include <string>

using namespace std;

class Building
{
private:
	string name;
	double size;
	string buildingAddress;

public:
	Building(string, double, string);
	~Building();
	string getName();
	void setName(string);
	double getSize();
	void setSize(double);
	string getBuildingAddress() const;
	void setBuildingAddress(string);
};

#endif

