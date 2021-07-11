/****************************************************************
Queue.h: This is the declaration file for my Queue class. It
contains the declaration of the QueueNode struct. Function
definitions are located in Queue.cpp.
***************************************************************/

#ifndef Queue_H
#define Queue_H

#include <iostream>

using namespace std;

class Queue
{
	struct QueueNode
	{
		int val;
		QueueNode* next;
		QueueNode* prev;
	};

private:
	QueueNode * head;  //no tail since this is a circular linked list 

public:
	Queue();   //constructor
	bool isEmpty();  //checks to see if Queue is empty
	void addBack(int);   //"push" adds to back of Queue
	int getFront();   //returns value at head of Queue
	void removeFront();       //"pop" deletes the current head node of the Queue
	void printQueue(); //displays the Queue to the screen
	~Queue();  //destructor
};
#endif

