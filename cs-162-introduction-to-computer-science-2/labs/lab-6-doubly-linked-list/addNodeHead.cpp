/*********************************************************
addNodeHead.cpp: Definition file for addNodeHead function.
This function will account for the situation in which the
linked list is empty. It returns a Node*.
*********************************************************/

#include "addNodeHead.h"

Node* addNodeHead(Node* head, Node * tail)
{
   int newVal;
   Node *temp;
   
   if( head == NULL)
   {
      cout << "\nPlease enter a postive integer: ";
      cin >> newVal;

      Node* newNode = new Node(newVal, NULL, NULL);
      head = newNode;
      tail = newNode;
      return head;
   }
   else
   {
      cout << "\nPlease enter a postive integer: ";
      cin >> newVal;
      Node* newNode = new Node(newVal, NULL, NULL);
      newNode->setNext(head);
      head->setPrevious(newNode);  
      head = newNode;
      return head;
    }
}
