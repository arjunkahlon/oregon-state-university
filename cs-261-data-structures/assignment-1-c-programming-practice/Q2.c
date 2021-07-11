/* CS261- Assignment 1 - Q.2*/
/* Name: Arjun Kahlon
 * Date: January 15th, 2019
 * Solution description: Distinguishes between local fuction variable pointers and main function. Show that the values in main won't change due to an address swap
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
    int* temp = a;
    a = b;
    b = temp;

    /*Decrement the value of integer variable c*/
    c--;

    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x, y, z, result;

    srand(time(0));
    x = rand() % 11;
    y = rand() % 11;
    z = rand() % 11;

    /*Print the values of x, y and z*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    result = foo(&x, &y, z);

    /*Print the values of x, y and z*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);

    /*Print the value returned by foo*/
     printf("The value returned by foo is %d", result);

   /*Question 1: Yes, the return value is the decremented value of z. It is 1 less*/
   /*Question 2: No, the values of x and y are unchanged. Swapping the addresses in pointer variables a and b had no effect on the values of integers x and y. All foo did was swap the memory address stored in the pointers.*/  

    return 0;
}
