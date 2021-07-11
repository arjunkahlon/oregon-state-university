/******************************************************
** Name: Arjun Kahlon
** Date: May 23, 2017
** Description: This function passes in the addresses of
** 3 int variables, and sorts them into ascending order
** by utilizing conditional statements.
********************************************************/

#include <iostream>

using namespace std;

void smallSort2(int *, int *, int *);

void smallSort2(int *a, int *b, int *c)
  {
    int temp = 0;         //used to swap int variables

    if(*a > *b)
    {
      temp = *a;
      *a = *b;
      *b = temp;
    }

    if (*b > *c)
    {
      temp = *b;
      *b = *c;
      *c = temp;
    }

    if (*a > *b)
    {
      temp = *a;
      *a = *b;
      *b = temp;
    }

  }

/*int main ()
{

int a = 14;
int b = -90;
int c = 2;

smallSort2(&a, &b, &c);
cout << a << ", " << b << ", " << c << endl;

return 0;
}*/

