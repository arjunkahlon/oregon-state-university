/***********************************************************
 ** Author: Arjun Kahlon 
 ** Date:   April 4th, 2017
 ** Description: Reads in user input for favorite animal and 
    outputs input to the screen
***********************************************************/

#include <iostream>
#include <string>

// a simple executable program
int main()
{
    std::string faveAnimal;
    std::cout << "Please enter your favorite animal." << std::endl;
    std::cin >> faveAnimal;
    std::cout << "Your favorite animal is the " << faveAnimal;
    std::cout << "." << std::endl;
  
    return 0;

}
