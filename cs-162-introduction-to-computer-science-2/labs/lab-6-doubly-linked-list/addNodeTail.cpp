/*********************************************************
addNodeTail.cpp: Definition file for addNodeTail function.
This function will account for the situation in which the 
linked list is empty.
*********************************************************/

#include "addNodeTail.h"

Node* addNodeTail(Node* head, Node* tail)
{
   int newValue;
   Node *temp;

   if (tail == NULL)
   {
      cout << "\nPlease enter a positive integer: ";
      cin >> newValue;

      Node* newNode = new Node(newValue, NULL, NULL);
      head = newNode;
      tail = newNode;
      return tail;
   }
   else
   {
      cout << "\nPlease enter a positive integer: ";
      cin >> newValue;

      Node* newNode = new Node(newValue, NULL, tail);
      temp = head;
      while(temp->getNext() != NULL)
      {
         temp = temp->getNext();
      }
      temp->setNext(newNode);
      tail = newNode;
      return tail;   
   }


}
