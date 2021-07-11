/***************************************************************
 *** Author : Arjun Kahlon
 *** Date: April 24, 2017
 *** Description: This program promps the user to enter 3 int values
 *** for int a, int b, int c amd plug those values into a function
 *** named smallSort. This function uses an int variable named temp 
 *** in order to sort a, b, c into ascending order. It accomplishes
 *** this by comparing a to b (and swapping if need be), comparing 
 *** b to c (swapping if need be) and the comparing a and b again
 *** swapping if need be. 
******************************************************************/

#include <iostream>

using namespace std;

void smallSort(int &a, int &b, int &c);   //function declaration

/*
int main ()
{
  int a, b, c;

  cout << "Please enter integer values for a, b, and c: " << endl;
  cin >> a >> b >> c;

  smallSort(a, b, c);  //function call
  cout << a << ", " << b << ", " << c << endl;

return 0;
}
*/

void smallSort (int &a, int &b, int &c)
{
int temp;  //used to swap

if (a > b)
{
   temp = a; //stores value in temp
   a = b;   //swap
   b = temp;   
}
if (b > c)
{
   temp = b;
   b = c;
   c = temp;
}
if (a > b)
{
   temp = a;
   a = b;
   b = temp;
}

}


