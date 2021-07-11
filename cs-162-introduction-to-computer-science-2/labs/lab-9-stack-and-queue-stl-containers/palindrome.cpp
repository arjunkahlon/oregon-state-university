/********************************************
palindrome.cpp: This is the definition file
for my palindrome function. 
********************************************/

#include "palindrome.h"

void palindrome()
{
	stack<char> s;
	string userInput;

	cout << "Please enter a string: ";
	getline(cin, userInput);

	for (int i = 0; i < userInput.size(); i++)  //traverses every character in string
	{
		s.push(userInput[i]);
		cout << userInput[i];
	}

	while (!s.empty())
	{
		cout << s.top(); //outputs top character in stack
		s.pop(); //removes top character
	}
        cout << endl;
}
