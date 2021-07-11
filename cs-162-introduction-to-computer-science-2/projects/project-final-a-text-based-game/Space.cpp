/************************************************************
Space.cpp: This is the declaration file for my Space class, 
which is an abstract class.
************************************************************/

#include "Space.h"



Space::Space()
{
	topSpace = rightSpace = leftSpace = bottomSpace = nullptr;  //initializes all the pointers to NULL
}

void Space::setRightLink(Space *s)   //sets Right Space
{
	rightSpace = s;
}

void Space::setLeftLink(Space *s)   //sets Left Space
{
	leftSpace = s;
}

void Space::setTopLink(Space* s)   //sets Top Space
{
	topSpace = s;
}

void Space::setBottomLink(Space* s)    //sets Bottom Space
{
	bottomSpace = s;
}

Space* Space::getRightLink()  //returns Right Space
{
	return rightSpace;
}

Space* Space::getLeftLink()   //returns left Space
{
	return leftSpace;
}

Space* Space::getTopLink()   //returns top Space
{
	return topSpace;
}

Space* Space::getBottomLink()  //returns bottom Space
{
	return bottomSpace;
}

Space * Space::move(Direction d)
{
	switch (d)
	{
	case up: 
		return topSpace;
	case down: 
		return bottomSpace;
	case left: 
		return leftSpace;
	case right:
		return rightSpace;
	}

	return nullptr;   //else return NULL
}

bool Space::checkWin()  //will be overridden in derived classes
{
	return false;
}

Space::~Space()
{
}
