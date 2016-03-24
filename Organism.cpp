//Organism Class Implementation file


#include "Organism.h"
#include "Human.h"
#include "Zombie.h"
using namespace std;

//Default Constructor
Organism::Organism(){}

//Constructor
Organism::Organism(City *city, int width, int height)
{
	this->city = city;
	this->width = width;
	this->height = height;
}//end Organism(parameters)

//Destructor
Organism::~Organism(){}

//Getters and Setters
void Organism::setPosition(int x, int y){this->x = x;this->y = y;}//end setPosition

void Organism::setHasMoved(bool hasMoved){this->hasMoved = hasMoved;}//end setHasMoved
bool Organism::getHasMoved(){return this->hasMoved;}

void Organism::setHasSpawned(bool hasSpawned){this->hasSpawned = hasSpawned;}//end setHasSpawned
bool Organism::getHasSpawned(){return this->hasSpawned;}//end getHasSpawned

void Organism::setSpawnCount(int spawnCount){this->spawnCount = spawnCount;} //end setSpawnCount
int Organism::getSpawnCount(){return this->spawnCount;}//end getSpawnCount

//friend functions
ostream& operator<<(ostream &output, Organism *organism)
{
	HANDLE  color = GetStdHandle(STD_OUTPUT_HANDLE); //Changes the output color

	//Depending on Human or Zombie, will ouput 'O' or 'X', respectfully
	if (dynamic_cast<Human*>(organism) != NULL) //Human
	{
		SetConsoleTextAttribute(color, HUMAN_COLOR);
		output << "O";
		SetConsoleTextAttribute(color, BOARD_COLOR);
	}
	else if (dynamic_cast<Zombie*>(organism) != NULL) //Zombie
	{
		SetConsoleTextAttribute(color, ZOMBIE_COLOR);
		output << "X";
		SetConsoleTextAttribute(color, BOARD_COLOR);
	}
	else //Empty space on grid
		output << " ";

	return output;
}//end operator<<








