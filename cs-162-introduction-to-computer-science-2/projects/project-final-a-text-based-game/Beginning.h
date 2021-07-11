/************************************************************
Beginning.h: This is the header file for my Beginning class. 
It is derived from Space, which is an abstract class.
************************************************************/

#ifndef Beginning_H
#define Beginning_H

#include "Space.h"
#include <iostream>

using namespace std;

class Beginning : public Space
{
private:
	string riddleHint = " ";  //initializes riddle hint
	bool pickedUpRiddle = false; //initilalizes riddle hint to not picked up

public:
	Beginning(string);
	virtual void printOptions();
	virtual bool validateChoice(int);
	virtual Space* doChoice(int, vector<string> *, int);
	virtual void reset();
	

	~Beginning();
};

#endif
