//Zombie Class Implementation file

#include "Zombie.h"
#include "Human.h"
using namespace std;

//Default Constructor
Zombie::Zombie(){}

//Constructor
Zombie::Zombie(City *city, int width, int height)
{
	this->city = city;
	this->width = width;
	this->height = height;
	this->starve = 0;
	srand(time(NULL));
}//end Zombie

//Destructor
Zombie::~Zombie(){}

//Methods overridden from super class
void Zombie::move(){

	//ZOMBIE TRIES TO EAT
	vector<int> moveDirections;
	//Checks all adjacent and diagonal cells to see if there is a human in it to eat.
	if (y - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x, y - 1)) != NULL){moveDirections.push_back(NORTH);}
	if (y + 1 < height && dynamic_cast<Human*>(city->getOrganism(x, y + 1)) != NULL){moveDirections.push_back(SOUTH);}
	if (x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y)) != NULL){moveDirections.push_back(EAST);}
	if (x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y)) != NULL){moveDirections.push_back(WEST);}
	if (y - 1 >= 0 && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y - 1)) != NULL){moveDirections.push_back(NORTH_EAST);}
	if (y + 1 < height && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y + 1)) != NULL){moveDirections.push_back(SOUTH_EAST);}
	if (y - 1 >= 0 && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y - 1)) != NULL){moveDirections.push_back(NORTH_WEST);}
	if (y + 1 < height && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y + 1)) != NULL){moveDirections.push_back(SOUTH_WEST);}

	//NO HUMAN TO EAT SO ZOMBIE MOVES
	if (!moveDirections.empty())
		this->setStarve(0);
	else
	{
		//ZOMBIE MOVES LIKE HUMAN IF NO HUMANS TO EAT
		this->setStarve(this->getStarve() + 1); //increments starveCount

		//Checking if there are valid move directions and adds to moveDirection vector
		if (y - 1 >= 0 && city->getOrganism(x, y - 1) == NULL){moveDirections.push_back(NORTH);}
		if (y + 1 < height && city->getOrganism(x, y + 1) == NULL){moveDirections.push_back(SOUTH);}
		if (x + 1 < width && city->getOrganism(x + 1, y) == NULL){moveDirections.push_back(EAST);}
		if (x - 1 >= 0 && city->getOrganism(x - 1, y) == NULL){moveDirections.push_back(WEST);}
	}//end else

	//random value from vector
	if (!moveDirections.empty()){
		int move = moveDirections.at(rand() % moveDirections.size());
		
		//Sets previous cell to Null
		city->setOrganism(NULL, x, y);

		//Sets the new position
		if (move == NORTH){this->setPosition(x, y - 1);}
		else if (move == SOUTH){this->setPosition(x, y + 1);}
		else if (move == EAST){this->setPosition(x + 1, y);}
		else if (move == WEST){this->setPosition(x - 1, y);}
		else if (move == NORTH_EAST){this->setPosition(x + 1, y - 1);}
		else if (move == SOUTH_EAST){this->setPosition(x + 1, y + 1);}
		else if (move == NORTH_WEST){this->setPosition(x - 1, y - 1);}
		else if (move == SOUTH_WEST){this->setPosition(x - 1, y + 1);}

		//adds the zombie to the city
		city->setOrganism(this, x, y);
	}//end if

	this->setHasMoved(true);
	this->starveZombie(); //calls method to check if zombie has starved.

}//end move

void Zombie::spawn(){

	//check if the zombie spawnCount limit is met
	if (this->getSpawnCount() >= ZOMBIE_BREED){
		vector<int> moveDirections;
		srand(time(NULL));

		//Check if human in adjacent cell or diagonal
		if (y - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x, y - 1)) != NULL){ moveDirections.push_back(NORTH); }
		if (y + 1 < height && dynamic_cast<Human*>(city->getOrganism(x, y + 1)) != NULL){ moveDirections.push_back(SOUTH); }
		if (x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y)) != NULL){ moveDirections.push_back(EAST); }
		if (x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y)) != NULL){ moveDirections.push_back(WEST); }
		if (y - 1 >= 0 && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y - 1)) != NULL){ moveDirections.push_back(NORTH_EAST); }
		if (y + 1 < height && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y + 1)) != NULL){ moveDirections.push_back(SOUTH_EAST); }
		if (y - 1 >= 0 && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y - 1)) != NULL){ moveDirections.push_back(NORTH_WEST); }
		if (y + 1 < height && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y + 1)) != NULL){ moveDirections.push_back(SOUTH_WEST); }

		//Check if there are values in the vector
		if (!moveDirections.empty())
		{
			int spawnGridSpot = moveDirections.at(rand() % moveDirections.size());//get random move from vector

			//create new zombie
			Zombie *myZombie = new Zombie(city, GRID_WIDTH, GRID_HEIGHT);

			//get zombie's new position
			if (spawnGridSpot == NORTH){myZombie->setPosition(x, y - 1);}
			else if (spawnGridSpot == SOUTH){myZombie->setPosition(x, y + 1);}
			else if (spawnGridSpot == EAST){myZombie->setPosition(x + 1, y);}
			else if (spawnGridSpot == WEST){myZombie->setPosition(x - 1, y);}
			else if (spawnGridSpot == NORTH_EAST){myZombie->setPosition(x + 1, y - 1);}
			else if (spawnGridSpot == SOUTH_EAST){myZombie->setPosition(x + 1, y + 1);}
			else if (spawnGridSpot == NORTH_WEST){myZombie->setPosition(x - 1, y - 1);}
			else if (spawnGridSpot == SOUTH_WEST){myZombie->setPosition(x - 1, y + 1);}

			city->setOrganism(myZombie, myZombie->x, myZombie->y);

			//set new zombie moved to true
			myZombie->setHasMoved(true);
			myZombie->setSpawnCount(0);
			myZombie->setHasSpawned(true);

			//reset if zombie has spawned
			this->setSpawnCount(0);
		}//end if

	}//end if

	else
		this->setSpawnCount(this->getSpawnCount() + 1); //increase the spawnCount
}//end spawn

//Getters and Setters
void Zombie::setStarve(int eat){ this->starve = eat; }
int Zombie::getStarve(){ return this->starve; }

void Zombie::starveZombie()
{
	//if zombie has not ate in 3 turns, it converts into a human
	if (this->getStarve() >= ZOMBIE_STARVE)
	{
		Human *myHuman = new Human(city, GRID_WIDTH, GRID_HEIGHT);
		myHuman->setPosition(x, y);
		city->setOrganism(myHuman, x, y);
	}//end if
}//end starveZombie
