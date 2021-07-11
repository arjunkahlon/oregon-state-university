/*****************************************************
triangular.cpp: This is the definition file for my
triangular function. It returns the triangular 
number of a passed in int variable.
*****************************************************/

#include "triangular.h"

int triangular(int n)
{

   if (n <= 0)
   {
      return -1;
   }
   else if (n == 1)
   {
      return 1;
   }
   else
   {  
      return triangular(n-1) + n;
   }
}
