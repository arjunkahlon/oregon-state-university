/***************************************************************
** Author : Arjun Kahlon
** Date: April 17, 2017
** Description: This program uses fstream to read in integer values 
** from a .txt file. The program adds all these values together and
** outputs the sum to a new file called "sum.txt".
*****************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
string fileName;
int sum = 0;
int input = 0;
ifstream inFile;
ofstream outFile;

cout << "What is the name of the file you're trying to open?" << endl;
getline (cin, fileName);

inFile.open(fileName);

inFile >> input;

while (!inFile.eof())
{
 sum += input;
 inFile >> input;
}


inFile.close();

outFile.open("sum.txt");
outFile << sum;
outFile.close();;

return 0;
}

