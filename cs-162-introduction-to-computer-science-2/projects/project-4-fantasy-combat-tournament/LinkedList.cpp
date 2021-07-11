/*************************************************************
LinkedList.cpp: This is the definition file for my LinkedList
class.
************************************************************/

#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = tail = NULL;
}

void LinkedList::addToFront(Character* character)
{
	Node* newNode = new Node;
	newNode->character = character;

	if (head == NULL )
	{
		newNode->next = NULL;
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

void LinkedList::addToBack(Character* character)
{
	Node* newNode = new Node;
	newNode->character = character;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

Character* LinkedList::removeFromFront()
{
	if (head == NULL)
	{
		return NULL;
	}

	Node* toDelete = head;
	Character* temp = head->character;
	head = head->next;
	if (head == NULL)
	{
		tail = NULL;
	}
	delete toDelete;
	return temp;
}

Character* LinkedList::removeFromBack()
{
	Node* currentNode = head;
	Character* temp;

	if (head == tail)
	{
		if (head == NULL)
		{
			return NULL;
		}
		temp = tail->character;
		head = tail = NULL;
	}
	else
	{
		temp = tail->character;
		while (currentNode->next != tail)
		{
			currentNode = currentNode->next;
		}
		Node* toDelete = tail;
		tail = currentNode;
		tail->next = NULL;
		currentNode = toDelete;
	}
	delete currentNode;
	return temp;
}

LinkedList::~LinkedList()      //this need to clear memory if list is not empty
{
	Node* traverse = head;
	Node* toDelete;

	while (traverse != NULL)
	{
		toDelete = traverse;
		traverse = traverse->next;
		delete toDelete;
	}
}

bool LinkedList::isEmpty()
{
	return (head == NULL);
}