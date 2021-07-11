/* CS261- Assignment 1 - Q. 0*/
/* Name: Arjun Kahlon
 * Date: January 15, 2018
 * Solution description: Pointer practice. Incrementing both pointer variable and address
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){

    /*Print the value and address of the integer pointed to by iptr*/
    printf("The value of the passed in integer in fooA is %d\n", *iptr);
    printf("The address of the passed in integer in fooA is %p\n", (void*)iptr);

    /*Increment the value of the integer pointed to by iptr by 5*/
    *iptr += 5;

    /*Print the address of iptr itself*/
    printf("The address of iptr %p\n", (void*)&iptr);

    /*Dummy variable, ignore the warning*/
    int c=5;
}


void fooB(int* jptr){

    /*Print the value and address of the integer pointed to by jptr*/
    printf("The value of the passed in integer in fooB is %d\n", *jptr);
    printf("The address of the passed in integer in fooB is %p\n", (void*)jptr);

    /*Decrement the address by 1 pointed to by jptr using jptr */
    jptr--;

    /*Print the address of jptr itself*/
    printf("The address of jptr is %p\n", (void*)jptr);
}


int main(){

    /*Declare an integer x and initialize it randomly to a value in [0,10] 
*/

    int x;

    srand((unsigned int)time(NULL));
    x = rand() % 11;

    /*Print the value and address of x*/
    printf("The value of x before fooA is %d\n", x);
    printf("The address of x is %p\n", (void*)&x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*Print the value of x*/
    printf("The value of x after fooA is %d\n", x);
    
    /*Question 1: Yes, the value of x is incremented by 5 in fooA. It is bigger by 5*/

    /*Call fooB() with the address of x*/
    fooB(&x);

    /*Print the value and address of x*/
    printf("The value of x after fooB is %d\n", x);
    printf("The address of x after fooB is %p\n", (void*)&x);

   /*Question 2: No, the value and address of x are unchanged. The only change is the address of jptr*/

    return 0;
}

