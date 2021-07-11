/* CS261- Assignment 1 - Q.3*/
/* Name: Arjun Kahlon
 * Date: January 15th, 2019
 * Solution description: implement a function that converts an inputed string into Camel case. Practice with char array. I struggled with the algorith but did my best.
 */

#include <stdio.h>
#include <stdlib.h>



char toUpperCase(char ch){
    /*Convert ch to upper case, assuming it is in lower case currently*/
    ch -= 32;
    return ch;
}

char toLowerCase(char ch){
    /*Convert ch to lower case, assuming it is in upper case currently*/
    ch += 32;
    return ch;
}

int stringLength(char s[]) {
    /*Return the length of the string*/
    int tally = 0;

    while(s[tally] != '\0'){
        tally++;
    }
    return tally;
}


void camelCase(char* word){
    /*Convert to camelCase*/
    int wordSize = stringLength((word));

    for (int i = 0; i < wordSize; i++) {
        if (word[i] == '_') {
            word[i] = toUpperCase(word[i + 1]);
            for (int j = i + 1; j < wordSize - 1; ++j) {
                word[j] = word[j + 1];
            }
            wordSize -= 1;
        }
    }
    word[wordSize] = 0;
}

int main(){

    char input[31];

    /*Read the string from the keyboard*/

    printf("\nPlease enter a string with up to 30 characters: ");
    scanf("%30[^\n]s", input);

    //converts all white spaces to underscores before calling camelCase
    for (int i = 0; i < stringLength(input); i++)
    {
        if (input[i] == ' ')
            input[i] = '_';
    }

    /*Call camelCase*/
    camelCase(input);

    /*Print the new string*/
    printf("\nThis is the output: %s", input);


    return 0;
}

