/***********************************************************
count_letters.cpp : This is the definition file for the
count_letters(function). The address of inFile and an int
pointer are passed in as paramters. This function counts 
until the next new line character. For the final paragraph,
it counts until the end of the file. 
**********************************************************/

#include "count_letters.hpp"

void count_letters(ifstream &inFile, int* letterFrequency)
{
   char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
   
   char capAlphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

   char value = ' ';
   inFile.get(value);

   while(value != '\n' && !inFile.eof()) //until new line or EOF
   {   
      for (int i = 0; i < 26; i++)
      {
         if (value == alphabet[i])    //compares value to lower case
         {
            letterFrequency[i] += 1;
         }
         else if (value == capAlphabet[i])  //compares value to upper case
         {
            letterFrequency[i] += 1;
         }
      } 
      inFile.get(value);  
   }

}
