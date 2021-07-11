/****************************************************************
Queue.cpp: This is the definition file for my Queue class. It
contains the functions for checking if empty, pushing to back,
returning value stored in head, printing Queue, pop the head,
as well as the constructor and destructor.
***************************************************************/

#include "Queue.h"

Queue::Queue()
{
	//initializes head to NULL
	head = NULL;
}

bool Queue::isEmpty()
{
	//Conditional that returns true if head is equal to NULL
	return (head == NULL);
}

void Queue::addBack(int  a)
{
	if (isEmpty())
	{
		//create a new head if queue is empty
		head = new QueueNode;
		head->val = a;

		//Only one value in queue
		head->next = head;
		head->prev = head;
	}
	else    //queue is not empty
	{
		//create new QueueNode pointer to store the head->prev (previous last value in queue)
		QueueNode* temp = head->prev;

		//create new QueueNode and store values
		QueueNode* newQueueNode = new QueueNode;
		newQueueNode->val = a;

		//stpres newQueueNode at end of queue
		newQueueNode->prev = temp;  
		newQueueNode->next = head;

        //connects the previous last node to the new last node as well as head to the new last node (circular)
		temp->next = newQueueNode;
		head->prev = newQueueNode;
	}
}

int Queue::getFront()
{
	//returns value at head of Queue
	return head->val;
}

void Queue::removeFront()
{
	if (isEmpty())
	{
		cout << "\n\nThere is no front node that can be removed. Queue is empty." << endl << endl;
		return;      //nothing occurs
	}
	else if (head == head->next)
	{
		//if head is the only Node in queue, we must delete the node and set the head pointer to NULL
		delete head;
		head = NULL;
	}
	else
	{
		//create new QueueNode pointer called toBeRemoved and have it point to head (to be removed)
		QueueNode* toBeRemoved = head;

		//sets head pointer to the head->next(since the former head is being removed)
		head = head->next;

		//connects new head Node to the former Head->previous and restablishes circle
		head->prev = toBeRemoved->prev;
		head->prev->next = head;
		delete toBeRemoved;
	}
}

void Queue::printQueue()
{
	if (!isEmpty())
	{
		QueueNode* current = head;

		cout << "\nYour queue is: ";
		cout << endl;

		//goes through Queue before reaching head again
		while (current->next != head)
		{
			cout << "\nValue: " << current->val;
			current = current->next;
		}

		cout << "\nValue: " << current->val;
	}
	else
	{
		cout << "\n\nThere are no stored values in Queue. Queue is empty." << endl;
	}
	cout << endl;
}
Queue::~Queue()
{
	while (!isEmpty())   //traverses Queue until the Queue is empty
	{
		//removes head from Queue
		removeFront();
	}
}

