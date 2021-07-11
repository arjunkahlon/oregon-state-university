#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
    //declare char pointer and call nextWord on file
    char* word = nextWord(file);

    while (word) 
    {
       //cput word on map
       hashMapPut(map, word, 1);
       //free memory pointed to by word
       free(word);
       //update word
       word = nextWord(file);
    }
    //free memory pointed to by word
    free(word);
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char answer[50];
    char inputBuffer[256];
    //bool variables for quit and add Word
    int addW = 0;
    int quit = 0;
    while (!quit)   
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        // Implement the spell checker code here..
        //if key is found
        if (hashMapContainsKey(map, inputBuffer)) 
        {
        	//create index
           int hIndex = HASH_FUNCTION(inputBuffer) % hashMapCapacity(map);

           //create link
           HashLink* link = map->table[hIndex];
           printf("Same Starting Letters:\n");

           while (link) 
           {  
              //traverses and prints each links key            
              printf("%s\n", link->key);
              //update link to its next
              link = link->next;
           }

        } //if quit is found, exit loop
        else if (strcmp(inputBuffer, "quit") == 0) 
        {
        	//updates bool variable quit to 1
           quit = 1;
        } 
        else 
        {
           //key is not found	
           printf("Not found.\n");
           
           //We need to add a word so we update addW to 1
           addW = 1;           

           while (addW) 
           {
           	  //prompt to add word. Recieved a char and stores it in answer
              printf("Add word to dictionary? Please answer y or  n: ");

              //store prompt answer into answer 
              scanf("%s", answer);

              //update addW to 0
              addW = 0;

              //compare user answer to y or Y and put word if both are equal
              if ((strcmp(answer, "y") == 0) || (strcmp(answer, "Y") == 0))
              {
              	 //puts word in dictionary.
                 hashMapPut(map, inputBuffer, 1);
              } //compares user answer to n or N
              else if ((strcmp(answer, "n") == 0) || (strcmp(answer, "N") == 0)) 
              {
                 printf("Word was not added\n");
              } 
              else 
              {
              	 //updates addW to 1
                 addW = 1;
              }
           }
        }
    }
    
    hashMapDelete(map);
    return 0;
}