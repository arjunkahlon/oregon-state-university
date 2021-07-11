#include "output_letters.hpp"
#include "count_letters.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
   string userRead;   //user input for input file
   string outPrint;   //user input for output file
   ifstream inFile;  //declares inFile stream
   ofstream outFile; //declares outFile stream
   int letterFrequency[26] = {0};  //initializes letterFrequency to 0
   bool userSuccess = false;  //changes to true if input file found


   cout << "\nThis program will read a file filled with letters, count the letter frequencies in the file, and output the results to a new file called output.txt." << endl;

   while (!userSuccess)
   {
      int fileNum = 1;
      cout << "\nPlease enter the name of the file (including file extension) that you would like to access: ";
      getline(cin, userRead);
      const char *mycharp = userRead.c_str();  //converts to const char*

      inFile.open(mycharp);    //opens input file using inFile

      if (inFile.fail())   //user input verficiation for input file name
      {
         cout << "\nSorry, the file name you entered does not exist. Please try again." << endl << endl;
      }
      else
      {
         userSuccess = true;

         while (!inFile.eof())    //while not end of file
         {
            cout << "What would you like to name output file " << fileNum++ << ": ";
            getline(cin, outPrint);
            const char *mycharp2 = outPrint.c_str(); //converts to const char* 
            outFile.open(mycharp2);  //opens output file
            count_letters(inFile, letterFrequency);  //counts letter frequency

            output_letters(outFile, letterFrequency); //outputs letter frequency
            outFile.close();   //closes output file
            for (int i = 0; i < 26; i++)
            {
               letterFrequency[i] = 0; //resets every index of letterFrequency to 0
            }
         }
         inFile.close();  //closes input file 
      }
    }  
  
return 0;
}
