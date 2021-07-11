/**************************************************
Node.h: Declaration file for Node class. Contains
member variables int val, as ewll as two pointers
of type Node (previous and next). Definitions in
Node.cpp.
**************************************************/

#ifndef Node_H
#define Node_H

#include <iostream>

using namespace std;

class Node
{
private:
	int val;
	Node *next, *prev;
public:
	Node();    //default constructor
	Node(int, Node*, Node*);  //constructor
	int getVal();
	void setVal(int);
	Node *getNext();
	Node *getPrevious();
	void setNext(Node*);
	void setPrevious(Node*);
	void Print();  //prints val in Node

	~Node();
};

#endif
