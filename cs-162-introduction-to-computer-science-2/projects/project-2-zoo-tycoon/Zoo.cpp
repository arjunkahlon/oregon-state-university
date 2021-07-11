/*************************************************************************
Zoo.cpp: This is the definition file for the Zoo class.
************************************************************************/

#include "Zoo.h"

Zoo::Zoo()            //initializes Zoo
{
	balance = 100000;   //starting balance
	sizeTiger = sizePenguin = sizeTurtle = 0;   //initializes the sizes of all animals to 0
	capacityTiger = capacityPenguin = capacityTurtle = 10;    //starting capacity of 10

	tigers = new Tiger*[capacityTiger];       //dynamically allocates array of Tiger pointers
	turtles = new Turtle*[capacityTurtle];    //dynamically allocates array of Turtle pointers
	penguins = new Penguin*[capacityPenguin]; //dynamically allocates array of Penguin pointers
}

double Zoo::getBalance()        //returns current balance
{
	return balance;
}

void Zoo::resizeArray(Animal ***animals, int &c, int s, int quantity)
{
	Animal** tempArray = *animals;  //sets old array to temp
	c = c * 2;                              //doubles capacity
	*animals = new Animal*[c];       //creates new array

	for (int i = 0; i < s; i++)
	{
		(*animals)[i] = tempArray[i];    //adds elements of temp to new array
	}

	delete[] tempArray;      //releases the memory for the temp array
}

void Zoo::buyAnimals(int quantity, int age, animal_t animal)   //reusable for any Animal object
{
	Animal* purchasedAnimal = addAnimals(quantity, age, animal);    //passes in addAnimals (defined below)
	balance -= (quantity * purchasedAnimal->getCost());     //subtracts cost of animal
}

Animal* Zoo::addAnimals(int quantity, int age, animal_t animal)
{
	switch (animal)       //switch between enumerated type called animal
	{
	case tiger:
		if ((sizeTiger + quantity) > capacityTiger)       //if size exceeds capacity
		{
			resizeArray((Animal***)&tigers, capacityTiger, sizeTiger, quantity);    //passes in resizeArray (defined above)
		}
		while (quantity >= 1)
		{
			tigers[sizeTiger] = new Tiger(age);   //adds Tiger object to the end of tiger array
			sizeTiger++;   //size increments with every new tiger being added
			quantity--;   //loop control variable decrements on each iteration
		}
		return tigers[sizeTiger-1];
	case penguin:
		if ((sizePenguin + quantity) > capacityPenguin)
		{
			resizeArray((Animal***)&penguins, capacityPenguin, sizePenguin, quantity);
		}
		while (quantity >= 1)
		{
			penguins[sizePenguin] = new Penguin(age);   //adds Penguin object to end of penguin array
			sizePenguin++;   //size increments with every new penguin being added
			quantity--;
		}
		return penguins[sizePenguin - 1];
	case turtle:
		if ((sizeTurtle + quantity) > capacityTurtle)
		{
			resizeArray((Animal***)turtles, capacityTurtle, sizeTurtle, quantity);
		}
		while (quantity >= 1)
		{
			turtles[sizeTurtle] = new Turtle(age);   //adds Turtle obejct to end of Turtle array
			sizeTurtle++;    //size increments iwth every new turtle being added
			quantity--;
		}
		return turtles[sizeTurtle-1];
	default:
		return NULL;
	}
}

void Zoo::removeAnimal(animal_t animal)
{
	switch (animal)
	{
	case tiger:
		sizeTiger--;
		delete tigers[sizeTiger]; //removes the last tiger in the array
		break;
	case penguin:
		sizePenguin--;
		delete penguins[sizePenguin];  //removes the last penguin in the array
		break;
	case turtle:
		sizeTurtle--;
		delete turtles[sizeTurtle];   //removes the last turtle in the array
		break;
	}


}

void Zoo::dayOccurs()
{
	int randNum = 0;        //determines random event
	int randNum2 = 0;       //determines random animal
	int bonus = 0;
	int payoff = 0;

	for (int i = 0; i < sizeTiger; i++)              //increments age and feeds all tigers in zoo
	{
		tigers[i]->incrementAge();
		balance -= tigers[i]->getBaseFoodCost();
	}
	for (int i = 0; i < sizePenguin; i++)            //increments age and feeds all penguins in zoo
	{
		penguins[i]->incrementAge();
		balance -= penguins[i]->getBaseFoodCost();
	}
	for (int i = 0; i < sizeTurtle; i++)            //increments age and feeds all turltes in zoo
	{
		turtles[i]->incrementAge();
		balance -= turtles[i]->getBaseFoodCost();
	}

	randNum = (rand() % 4);    //randomly generates number for event
	randNum2 = (rand() % 3);   //randomly generates number to determine animal type

	switch (randNum)
	{
	case 0:
	{
		cout << "\nA sickness has occured to an animal in the zoo" << endl;
		if (randNum2 == 0)
		{
			cout << "\nA tiger has died." << endl;
			removeAnimal(tiger);     //removes tiger from tiger array
		}
		if (randNum2 == 1)
		{
			cout << "\nA penguin has died." << endl;
			removeAnimal(penguin);   //removes penguin from end of penguin array
		}
		if (randNum2 == 2)
		{
			cout << "\nA turtle has died." << endl;
			removeAnimal(turtle);    //removes turtle from end of turtle array
		}
	}
	    break;
	case 1:
	{
		cout << "\nThere has been a boom in zoo attendance" << endl;
		bonus = ((rand() % 251) + 250) * sizeTiger;     //calculates bonus
	}
	    break;
	case 2:
	{
		if(randNum2 == 0)
		{
			cout << "\nA baby tiger has been born" << endl;
			addAnimals(1, 0, tiger);
		}
		if(randNum2 == 1)
		{
			cout << "\n10 baby turtles have been born." << endl;
			addAnimals(10, 0, turtle);
		}
		if(randNum2 == 2)
		{
			cout << "\n5 baby penguins have been born." << endl;
			addAnimals(5, 0, penguin);
		}


		/*Animal* babyAnimal = addAnimals(1, 0, static_cast<animal_t>(randNum2));      //adds a baby animal based on RNG animal type
		cout << "\nA baby " << babyAnimal->getAnimalType() << " has been born" << endl;    //outputs what type of baby was born*/

		/*for(int i = 0; i < sizeTiger; i++)
		{
			if (tigers[i]->getAge() >= 3)
			{
				tigerFertile = true;
			}
		}

		for(int i = 0; i < sizePenguin; i++)
		{
			if (penguins[i]->getAge() >= 3)
			{
				penguinFertile = true;
			}
		}

		for(int i = 0; i < sizeTurtle; i++)
		{
			if (turtles[i]->getAge() >= 3)
			{
				turtleFertile = true;
			}
		}

		if (tigerFertile && penguinFertile && turtleFertile)
		{
			allInfertile = false;
		}
		if (!tigerFertile && !penguinFertile && !turtleFertile)
		{
			allInfertile = true;
			cout << "\nNo animals in the zoo are old enough to have babies" << endl;
		}

		babySuccess = false;

		if (!allInfertile)
		{
		   do
		   {
		      if (randNum2 == 0 && tigerFertile)
		      {
		          cout << "\nA baby tiger has been born" << endl;
			      addAnimals(1, 0, tiger);
			      babySuccess = true;
		      }
		      if(randNum2 == 1 && turtleFertile)
		      {
			      cout << "\n10 baby turtles have been born" << endl;
			      addAnimals(10, 0, turtle);
			      babySuccess = true;
		      }
		      if(randNum2 == 2 && penguinFertile)
		      {
			      cout << "\n5 baby penguins have been born" << endl;
			      addAnimals(5, 0, penguin);
			      babySuccess = true;
		      }

		      if(babySuccess == false)
		      {
		      	randNum2 = (rand() % 3);
		      }
		   } while(!babySuccess);
		}*/

	}
		break;
	default:
		cout << "\nNothing unordinary happens today" << endl;    //nothing happens
	}

	if (sizeTiger > 0)
	{
		payoff = (tigers[0]->getPayoff()) * sizeTiger;     //calculates tiger payoff
	}
	if (sizePenguin > 0)
	{
		payoff += (penguins[0]->getPayoff()) * sizePenguin;    //calculates penguin payoff
	}
	if (sizeTurtle > 0)
	{
		payoff += (turtles[0]->getPayoff()) * sizeTurtle;    //calculates turtle payoff
	}
	balance += (payoff + bonus);    //calculates balance
}

/*void Zoo::deleteArrays()     //frees the memory to ensure no memory leak
{
	for (int i = 0; i < sizeTiger; i++)
	{
		delete[] tigers [i];
	}
	for (int i = 0; i < sizeTurtle; i++)
	{
		delete[] turtles [i];
	}
	for (int i = 0; i < sizePenguin; i++)
	{
		delete[] penguins [i];
	}


	delete[] tigers;
	delete[] turtles;
	delete[] penguins;
}*/