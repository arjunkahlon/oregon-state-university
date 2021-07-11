/************************************************************
Space.h: THis is the abstract class Space. It will be derived
into Beginning, Passage, and Final. The delcarations are found
in Space.cpp.
************************************************************/

#ifndef Space_H
#define Space_H

#include <string>
#include <vector>

using namespace std;

class Space
{

private: 
	Space *topSpace, *rightSpace, *leftSpace, *bottomSpace;  //these pointers will connects Space objects

public:
	enum Direction {up, down, left, right};

	Space();
	void setRightLink(Space*);
	void setLeftLink(Space*);
	void setTopLink(Space*);
	void setBottomLink(Space*);

	Space* getRightLink();
	Space* getLeftLink();
	Space* getTopLink();
	Space* getBottomLink();
	virtual void printOptions() = 0; 
	virtual bool validateChoice(int) = 0;
	virtual Space* doChoice(int, vector<string> *, int) = 0;
	virtual bool checkWin();
	virtual void reset() = 0;
	
	Space* move(Direction);
	~Space();
};

#endif

