/*************************************************************
Queue.h: This is the definition file for my Queue class.
************************************************************/

#include "Queue.h"



Queue::Queue()
{
}

void Queue::insert(Character* character)  //adds to back of Queue
{
	addToBack(character);
}

Character* Queue::remove()    //removes from front
{
	return removeFromFront();
}


Queue::~Queue()
{
}
