//City Class Implementation file

#include "City.h"
#include "Human.h"
#include "Zombie.h"
#include "Organism.h"
using namespace std;


//Constructor
City::City()
{
	//populating the city to initialize every spot on grid to NULL
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int j = 0; j < GRID_WIDTH; j++)
			grid[j][i] = NULL;
	}//end for
}//end City

//Destructor
City::~City(){}//end ~City


//Getters and Setters
Organism *City::getOrganism(int x, int y){return this->grid[x][y];}//end getOrganism
void City::setOrganism(Organism *organism, int x, int y){grid[x][y] = organism;}//end setOrganism


//Methods
void City::move() //first sets all to false, then move, then spawn
{
	//Sets the initial bool move for all organism to false
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int j = 0; j < GRID_WIDTH; j++)
		{
			if(grid[j][i] != NULL)
			{
				grid[j][i]->setHasMoved(false);
				grid[j][i]->setHasSpawned(false);
			}//end for
		}//end for
	}//end for


	//This sets organisms move
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int j = 0; j < GRID_WIDTH; j++)
		{
			if (grid[j][i] != NULL)
			{
				if (grid[j][i]->getHasMoved() == false)
					grid[j][i]->move();
			}//end if
		}//end for
	}//end for



	//This sets organism to spawn
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int j = 0; j < GRID_WIDTH; j++)
		{
			if (grid[j][i] != NULL)
			{
				if (grid[j][i]->getHasSpawned() == false)
					grid[j][i]->spawn();
			}//end if
		}//end for
	}//end for
}//end move


//Returns the number of Humans
int City::numberOfHumans()
{
	int humans = 0;
	for (int i = 0; i<GRID_HEIGHT; i++)
	{
		for (int j = 0; j<GRID_WIDTH; j++)
		{
			if (dynamic_cast<Human*>(grid[j][i]) != NULL)
				humans++;
		}//end for
	}//end for

	return humans;
}//end numberOfHumans

int City::numberOfZombies()
{
	int zombies = 0;
	for (int i = 0; i<GRID_HEIGHT; i++)
	{
		for (int j = 0; j<GRID_WIDTH; j++)
		{
			if (dynamic_cast<Zombie*>(grid[j][i]) != NULL)
				zombies++;
		}//end for
	}//end for
	return zombies;
}//end numberOfZombies

//friend functions
//override output operator
ostream& operator<<(ostream &output, City &city)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 }); //This sets the console to be fixed.

	//Welcome Message
	cout << "     Welcome to the Predator Vs Prey Simulation!" <<endl<<endl;
	
	//Draw the City
	for (int i = 0; i<GRID_HEIGHT; i++)
	{
		output << "     |";
		for (int j = 0; j<GRID_WIDTH; j++)
			output << city.grid[j][i] << "|";
		output << endl;
	}//end for

	

	return output;
}//end operator<<