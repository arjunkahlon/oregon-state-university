/*********************************************************
main.cpp    Main funciton
*********************************************************/

#include "Node.h"
#include "printMenu.h"
#include "addNodeHead.h"
#include "addNodeTail.h"
#include "printList.h"

int main()
{
   Node *head = NULL; 
   Node* tail = NULL; 
   Node *traverse = NULL;
   Node* deleteHead = NULL;
   Node* deleteTail = NULL;
   int userChoice; 

   do
   {
      userChoice = printMenu();

      switch(userChoice)
      {
         case 1:
            if (head == NULL || tail == NULL) //accounts for empty list
            { 
               head = tail = addNodeHead(head, tail);
            }
            else
            {
               head = addNodeHead(head, tail);  
            }
            printList(head, tail, traverse, false);
            break;
         case 2:
            if (head == NULL || tail == NULL) //accounts for empty list
            {
                tail = head = addNodeTail(head, tail);
            } 
            else
            {
                tail = addNodeTail(head, tail);
            }
            printList(head, tail, traverse, false);
            break;
         case 3:
            //delete from head
            if(head->getNext() != NULL)
            {
               deleteHead = head;
               head = head->getNext();
               head->setPrevious(NULL);
               delete deleteHead;
               printList(head, tail, traverse, false);
            }
            else
            {
               cout << "\n\nCannot delete sole value in linked list." << endl;
            }
            break;
         case 4:
           // delete from tail
            if(tail->getPrevious() != NULL)
            {
               deleteTail = tail;
               tail = tail->getPrevious();
               tail->setNext(NULL);
               delete deleteTail;
               printList(head, tail, traverse, false);
             }
             else
             {
                cout << "\n\nCannot delete sole value in linked list." << endl;
             }
            break;
         case 5:
            //traverse reversely
            printList(head, tail, traverse, true);
            break;
         case 6:
            cout << "\nProgram will now exit." << endl << endl; 
            break;
      }

   }while(userChoice != 6);
   
   delete head;
   delete tail;
   delete traverse;

   return 0;
}
