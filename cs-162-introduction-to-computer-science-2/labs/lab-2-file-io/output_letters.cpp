/*******************************************************
output_letters.hpp : This is the declaration file for 
my output_letters() function. The address location of
outFile and an int pointer are passed in as parameters.
This function uses outFile to print to a an output file.
******************************************************/

#include "output_letters.hpp"

void output_letters(ofstream &outFile, int* letterFreq)
{
   char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

   for (int i = 0; i < 26; i++)  //outputs frequency of each alphabet 
   {
      outFile << alphabet[i] << ":  " << letterFreq[i] << endl;
   }

}
