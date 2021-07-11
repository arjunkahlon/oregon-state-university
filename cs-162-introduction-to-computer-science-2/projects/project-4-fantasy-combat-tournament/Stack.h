/*************************************************************
Stack.h: This is the declaration file for my Stack class. It is
derives from my LinkedList class.
************************************************************/
#include "LinkedList.h"

class Stack : public LinkedList
{
public:
	Stack();
	void push(Character*);
	Character* pop();
	~Stack();
};

