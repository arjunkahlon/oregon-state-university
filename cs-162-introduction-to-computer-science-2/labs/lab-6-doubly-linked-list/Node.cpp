/**************************************************
Node.cpp: Definition file for Node class.
**************************************************/

#include "Node.h"



Node::Node()
{
	this->next = NULL;
	this->prev = NULL;
	this->val = 0;
}

Node::Node(int v, Node* n, Node* p)
{
   next = n;
   prev = p;
   this->val = v;
}

int Node::getVal()
{
   return val;
}

void Node::setVal(int i)
{
   this->val = i;
}

Node* Node::getNext()
{
   return this->next;
}

void Node::setNext(Node* newNext)
{
   this->next = newNext;
}

Node* Node::getPrevious()
{
   return this->prev;
}

void Node::setPrevious(Node* newPrevious)
{
   this->prev = newPrevious;
}

void Node::Print()
{
	cout << "Val: " << getVal() << endl;
}

Node::~Node()
{
}
