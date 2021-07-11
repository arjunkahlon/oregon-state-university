#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>

//referenced Chegg for help implementing these functions to ensure program would compile
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
//Fix me: Do the necessary change to make the implementation //case-insensitive  
   while (1) 
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')  
        {
            /*case sensitive implementation causing compile error
            if (c >= 'A' && c <= 'Z') 
            {
				c = toLowerCase(c);
			}*/

            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            // .............
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
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);
    
    clock_t timer = clock();
    
    HashMap* map = hashMapNew(10);
    
    // --- Concordance code begins here ---
    // Be sure to free the word after you are done with it here.
    
	//Declare pointer to read file
	FILE * fileR;

	//fopen to open file input1.txt
	fileR = fopen(fileName, "r");

	// If file not found
	if (fileR == NULL) 
	{
		//prints error if file not found
		perror("Error");
	}
    //updates pointer and traverses words
	char * word = nextWord(fileR);

	while (word != NULL) 
	{
        //if key found
		if (hashMapContainsKey(map, word)) 
		{
			//declare int cWord 
			int cWord = *(hashMapGet(map, word));
			//put word into hash map
			hashMapPut(map, word, ++cWord);
		}
		else 
		{
			//if not found, put word into hash map
			hashMapPut(map, word, 1);
		}
        //frees memory of word
		free(word);

		//updates word to next word in file
		word = nextWord(fileR);
	}
	
	
	// Close file
	fclose(fileR);

    //concordance print
	for (int i = 0; i < map->capacity; i++)
	{
		//create traversal link and set it to index
		HashLink* link = map->table[i];
		if (link != NULL)
		{
			while (link)
			{
				//prints key and value
				printf(" %s: %d \n", link->key, link->value);

				//updates link
				link = link->next;
			}
		}
	}

    // --- Concordance code ends here ---
    
    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));
    
    hashMapDelete(map);
    return 0;
}