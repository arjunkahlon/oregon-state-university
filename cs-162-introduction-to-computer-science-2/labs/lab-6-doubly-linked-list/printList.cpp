/*********************************************************
printList.cpp: Definitionn file for printList function.
Includes both regular and reverse print based on a passed
in bool variable.
*********************************************************/

#include "printList.h"

void printList(Node* head, Node* tail, Node* traverse, bool reverse)
{
   if(reverse == false)
   {
 
      traverse = head;
      while (traverse != NULL)
      {
         traverse->Print();
         traverse = traverse->getNext();
      }
   }
   else if(reverse == true)   //prints reverse list
   {
      traverse = tail;
      while (traverse != NULL)
      {
        traverse->Print();
        traverse = traverse->getPrevious();
      }
   }
}
