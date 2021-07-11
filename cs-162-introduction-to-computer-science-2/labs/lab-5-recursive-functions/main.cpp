#include "reverseString.h"
#include "arraySum.h"
#include "triangular.h"

#include <limits>

//int getInput(int min, int max);

int main()
{
   int *array;  //pointer that will be passed into arraySum
   int arraySize, menuChoice, n = 0;  
   string reverse = "";   //string that gets reversed
   bool menuExit = false;    //menu loop

   do
   {
      cout << "\n1. Reverse a string." << endl;
      cout << "2. Find the sum of an array of integers." << endl;
      cout << "3. Find traingular number of an integer." << endl;
      cout << "4. Exit" << endl;
      cout << "\nChoose from the above options: ";
      //menuChoice = getInput(1,4);
      cin >> menuChoice;
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cin.clear();

      switch(menuChoice)
      {
         case 1:     //reverse String 
           cout << "\nPlease enter the string you would like reversed: ";
           getline(cin, reverse);
           cout << endl; 
           reverseString(reverse);
           break;
         case 2:   //array Sum
            cout << "\nThis will find the sum of array of integers" << endl;
            cout << "\n\nEnter Array Size: ";
            cin >> arraySize;
            array = new int[arraySize];

            cout << "\n\nEnter elements of Array seperate by a space: ";
            for(int i = 0; i < arraySize; i++)
            {
               cin >> * (array + i);
            }
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.clear();

            cout << "\nThe Sum of the array is: " << arraySum(array, arraySize) << endl;
            break;
         case 3:    //triangular number 
            cout << "\nEnter an int that you would like to calculate the triangular number of: ";
            cin >> n;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.clear();
            cout << "\nThe triangular number of " << n << " is " << triangular(n) << endl;
            break;
         case 4:    //Program exit
             cout << "\nProgram will now exit" << endl;
             menuExit = true;   //program exit
             break;
         default:
            cout << "\nInvalid Input" << endl;
       }
   }while(!menuExit);





return 0;
}

/*int getInput(int min, int max)
{
   int userInput;

   do 
  {
     cin >> userInput;
     if(userInput < min || userInput > max)
     { 
        cout << "\nPlease enter a choice from " << min << " to " << max  << ": ";
     }
     if(cin.fail())
     {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }
   }while(userInput < min || userInput > max);

  return userInput;
}*/
