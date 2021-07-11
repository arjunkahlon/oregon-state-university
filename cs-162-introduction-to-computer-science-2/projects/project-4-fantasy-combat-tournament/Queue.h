/*************************************************************
Queue.h: This is the header file for my Queue class. It is
derives from my LinkedList class.
************************************************************/

#include "LinkedList.h"

class Queue : public LinkedList
{
public:
	Queue();
	void insert(Character*);
	Character* remove();
	~Queue();
};

