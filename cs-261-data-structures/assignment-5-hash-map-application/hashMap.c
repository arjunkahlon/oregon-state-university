/*
 * CS 261 Data Structures
 * Assignment 5
 * Name: Arjun Kahlon
 * Date: March 4th, 2019
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int hashFunction1(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += (i + 1) * key[i];
    }
    return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink* hashLinkNew(const char* key, int value, HashLink* next)
{
    HashLink* link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink* link)
{
    free(link->key);
    free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap* map, int capacity)
{
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        map->table[i] = NULL;
    }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap* map)
{
    // FIXME: implement
    assert(map != NULL);

    //create iterator to go through each link
    struct HashLink *current;
    //create next struct
    struct HashLink *next;

    //loop through the map
    for(int i = 0; i < map->capacity; i++)
    {
        current = map->table[i];
        if(current != NULL){
            do {
            	//update next to current's next and delete current
                next = current->next;
                hashLinkDelete(current);
                //update current to next
                current = next;
            } while (next != NULL);
        }
    }
    //free the map
    free(map->table);
    //reset size to 0 and set table to NULL
    map->size = 0;
    map->table = NULL;
}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap* hashMapNew(int capacity)
{
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap* map)
{
    hashMapCleanUp(map);
    free(map);
}

/**
 * Returns a pointer to the value of the link with the given key  and skip traversing as well. Returns NULL
 * if no link with that key is in the table.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int* hashMapGet(HashMap* map, const char* key)
{
    // FIXME: implement
    assert(map != NULL);
    assert(key != NULL);

    int hIndex = HASH_FUNCTION(key) % map->capacity;
    
    //declare new struct to traverse
    struct HashLink *current = map->table[hIndex];

    while(current != NULL)
    {
    	//return if current->key = key
        if(strcmp(current->key, key) == 0)
            return &(current->value);
        else
        	//update  current to next
            current = current->next;
    }
    //default return
    return NULL;
}

/**
 * Resizes the hash table to have a number of buckets equal to the given 
 * capacity (double of the old capacity). After allocating the new table, 
 * all of the links need to rehashed into it because the capacity has changed.
 * 
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 * 
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap* map, int capacity)
{
    // FIXME: implement

    //store old map's capacity
    int oldCap = map->capacity;

    //create new map with new capacity
    HashMap* newMap = hashMapNew(capacity);
    
    //we will iterate through old map and fill newMap
    for (int i = 0; i < oldCap; i++) 
    {
    	//create link and store table index
        HashLink* link = map->table[i];

        while (link) 
        {
           //store link vales into newMap	
           hashMapPut(newMap, link->key, link->value);
           //update link to next
           link = link->next;
        }
    }
    
    //re=initialize map
    hashMapCleanUp(map);

    //set map->table pointer to newMap->table
    map->table = newMap->table;

    //set map->size to newMap->size
    map->size = newMap->size;

     //set map->capacity to newMap->capacity
    map->capacity = newMap->capacity;
    
    //free newMap
    free(newMap);
}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value and skip traversing. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket.
 * 
 * @param map
 * @param key
 * @param value
 */
void hashMapPut(HashMap* map, const char* key, int value)
{
    // FIXME: implement
   if(hashMapTableLoad(map) > MAX_TABLE_LOAD)
   {
        resizeTable(map, 2 * hashMapCapacity(map));
    }

   //create index
   int hIndex = HASH_FUNCTION(key) % hashMapCapacity(map);
   
   if(hIndex < 0) 
    {
    	hIndex += hashMapCapacity(map);
    }

    //create two links. one to traverse and one to add
    struct HashLink *current= map->table[hIndex];
    //intialize newLink to NULL
    struct HashLink *newLink= NULL;


    while (current != NULL) 
    {
        if (strcmp(current->key, key) == 0)
        {
            //link with key already exists so we update value and exit function
            current->value = value;
            //exit function
            return;
        }
        //update current to next to keep traversing
        current = current->next;
    }

    //create new link if link with given key does not exist
    newLink = hashLinkNew(key, value, map->table[hIndex]);
    map->table[hIndex] = newLink;
    map->size++;
    return;
}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap* map, const char* key)
{
    // FIXME: implement
    //assertions 
     assert(map != NULL);
     assert(key != NULL);

    //create index
    int hIndex = HASH_FUNCTION(key) % hashMapCapacity(map);
    if(hIndex < 0) 
    {
    	hIndex += map->capacity;
    }
    
    //create current link to iterate the table
    struct HashLink *current = map->table[hIndex];

    //create next link to update current
    struct HashLink *nxt = map->table[hIndex]->next;
    
    //we will exit the function if current is equal to NULL
    if(current == NULL)
    {
    	//there is nothing to remove so we exit function
    	printf("No links to remove\n");
        return;
    }

    if(strcmp(current->key, key) == 0)
    {
    	//delete the current link
        hashLinkDelete(current);

        //update the map index to current's next
        map->table[hIndex] = nxt;

        //decrement the size of the map
        map->size--;

        //exit function
        return;
    }

    while(nxt != NULL)
    {
    	//we check to see if current's next key is equal to key
        if(strcmp(nxt->key, key) == 0)
        {
        	//set current's next to curren't next's next
            current->next = nxt->next;

            //delete nxt (curren't previous next)
            hashLinkDelete(nxt);

            //decrement map size
            map->size--;
            return;
        } 
        else 
        {
        	//update current to current's next
            current = current->next;
            //update nzxt to its next
            nxt = nxt->next;
        }
    }
}

/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap* map, const char* key)
{
    // FIXME: implement
    assert(map != NULL);
    assert(key != NULL);
    //create index
    int hIndex = HASH_FUNCTION(key) % hashMapCapacity(map);
    if(hIndex < 0) 
    {
    	hIndex += map->capacity;
    }

    //create current link 
    struct HashLink *current = map->table[hIndex];
    //traverse and return 1 if found
    while(current != NULL)
    {
        if(strcmp(current->key, key) == 0)
            return 1;
        //else, update current to current's next
        current = current->next;
    }
    //return 0 for false if not found
    return 0;
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap* map)
{
    // FIXME: implement
    //return map size
        return map->size;

}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap* map)
{
    // FIXME: implement
    //return map capacity
     return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap* map)
{
    // FIXME: implement
    int emptyBucketCount = 0;

    for(int i = 0; i < hashMapCapacity(map); i++)
    {
        if(map->table[i] == NULL)
        {
        	//increment emptyBucketCount every time a NULL is encountered
            emptyBucketCount++;
        }
    }
    //return total count of empty buckets
    return emptyBucketCount;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap* map)
{
    // FIXME: implement
    assert(map != NULL);
    //size divided by capacity
    return (float)hashMapSize(map) / hashMapCapacity(map);
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap* map)
{
  // FIXME: implement
    for (int i = 0; i < hashMapCapacity(map); i++)
    {
        HashLink* current = map->table[i];
        if (current != NULL)
        {
            printf("\nBucket %i ->", i);
            while (current != NULL)
            {
                printf(" (%s, %d) ->", current->key, current->value);
                current = current->next;
            }
        }
    }
    printf("\n");
}
