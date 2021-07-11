/*************************************************************
Stack.h: This is the definition file for my Stack class.
************************************************************/

#include "Stack.h"

Stack::Stack()
{
}

void Stack::push(Character* character)  //pushes to front
{
	addToFront(character);
}

Character* Stack::pop()     //removes Character from front
{
	return removeFromFront();
}


Stack::~Stack()
{
}
