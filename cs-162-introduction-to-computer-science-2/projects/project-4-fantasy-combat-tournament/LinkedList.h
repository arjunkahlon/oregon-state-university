/*************************************************************
LinkedList.h: This is the header file for my LinkedList class. Queue and
Stack are derives from this class.
************************************************************/

#ifndef LinkedList_H
#define LinkedList_H
#include "Character.h"

class LinkedList
{
	struct Node
	{
		Character* character;
		Node* next;
	};

	Node *head, *tail;

protected:
	void addToFront(Character*);
	void addToBack(Character*);
	Character* removeFromFront();
	Character* removeFromBack();
public:
	LinkedList();
	~LinkedList();
	bool isEmpty();
};
#endif
