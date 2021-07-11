/**************************************************
 *Arjun Kahlon
 *stackapp.c 
 * ************************************************/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
			
*/
char nextChar(char* s)
{
    static int i = -1;
    char c;
    ++i;
    c = *(s+i);
    if ( c == '\0' )
        return '\0';
    else
        return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
*/
int isBalanced(char* s)
{
    /* FIXME: You will write this function */
    if (s == 0 || *s == '\0')
    {
       return 1;
    }

    struct DynArr* stack = newDynArr(1);
    int i  = 0;
    while(s[i] != '\0'){

        switch (s[i]) {

            case '(' :
            case '{' :
            case '[' :
                //all of them
                pushDynArr(stack, s[i]);
                break;
            case ')' :
                if (!isEmptyDynArr(stack))
                {
                    if(topDynArr(stack) == '('){
                        popDynArr(stack);
                    }
                    else {
                        return 0;
                    }
                }
                else{
                    return 0;
                }
                break;
            case '}' :
                if (!isEmptyDynArr(stack))
                {
                    if(topDynArr(stack) == '{'){
                        popDynArr(stack);
                    }
                    else {
                        return 0;
                    }
                }
                else{
                    return 0;
                }
                break;
            case ']' :
                if (!isEmptyDynArr(stack))
                {
                    if(topDynArr(stack) == '['){
                        popDynArr(stack);
                    }
                    else {
                        return 0;
                    }
                }
                else{
                    return 0;
                }
                break;
        }

        i++;
    }
    if(isEmptyDynArr(stack)) {
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[]){

    char* s=argv[1];
    int res;

    printf("Assignment 2\n");

    res = isBalanced(s);

    if (res)
        printf("The string %s is balanced\n",s);
    else
        printf("The string %s is not balanced\n",s);

    return 0;
}

