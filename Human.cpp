//Human Class Implementation file

#include "Human.h"
using namespace std;


//reference for srand: http://www.cplusplus.com/reference/cstdlib/srand/

//Default Constructor
Human::Human(){}

//Constructor
Human::Human(City *city, int width, int height)
{
	this->city = city;
	this->width = width;
	this->height = height;
	srand(time(NULL));
}//end Human (parameters)

//Destructor
Human::~Human(){}

//Methods from superclass Organism
void Human::move()
{
	vector<int> moveDirections; //Dynamically stores the valid move directions.

	if (y - 1 >= 0 && city->getOrganism(x, y - 1) == NULL){moveDirections.push_back(NORTH);} //push_back adds an element at the end of the vector array.
	if (y + 1 < height && city->getOrganism(x, y + 1) == NULL){moveDirections.push_back(SOUTH);}
	if (x - 1 >= 0 && city->getOrganism(x - 1, y) == NULL){ moveDirections.push_back(WEST); }
	if (x + 1 < width && city->getOrganism(x + 1, y) == NULL){moveDirections.push_back(EAST);}
	
	if (!moveDirections.empty())
	{
		//Select a random value from moveDirections vector
		int move = moveDirections.at(rand() % moveDirections.size());

		city->setOrganism(NULL, x, y); //previous position is now NULL

		//Add the human to the new position
		if (move == NORTH){this->setPosition(x, y - 1);}
		else if (move == SOUTH){this->setPosition(x, y + 1);}
		else if (move == EAST){this->setPosition(x + 1, y);}
		else if (move == WEST){this->setPosition(x - 1, y);}

		city->setOrganism(this, x, y); //add human to the city
	}//end if

	//set moved to true
	this->setHasMoved(true);

}//end move


void Human::spawn(){

	//check if the human spawnCount limit is met
	if (this->getSpawnCount() >= HUMAN_BREED)
	{
		vector<int> moveDirections;
		srand(time(NULL));

		//stores the valid move directions into the vector
		if (y - 1 >= 0 && city->getOrganism(x, y - 1) == NULL){moveDirections.push_back(NORTH);}
		if (y + 1 < height && city->getOrganism(x, y + 1) == NULL){moveDirections.push_back(SOUTH);}
		if (x + 1 < width && city->getOrganism(x + 1, y) == NULL){moveDirections.push_back(EAST);}
		if (x - 1 >= 0 && city->getOrganism(x - 1, y) == NULL){moveDirections.push_back(WEST);}

		//get random move from vector
		if (!moveDirections.empty()){
			int spawnGridSpot = moveDirections.at(rand() % moveDirections.size()); //Generates the random value from moveDirection vector

			//creates a new human
			Human *myHuman = new Human(city, GRID_WIDTH, GRID_HEIGHT);

			//human's new position is set
			if (spawnGridSpot == NORTH){myHuman->setPosition(x, y - 1);}
			else if (spawnGridSpot == SOUTH){myHuman->setPosition(x, y + 1);}
			else if (spawnGridSpot == EAST){myHuman->setPosition(x + 1, y);}
			else if (spawnGridSpot == WEST){myHuman->setPosition(x - 1, y);}

			//set the human in the city
			city->setOrganism(myHuman, myHuman->x, myHuman->y);

			//Human has now moved
			myHuman->setHasMoved(true);
			myHuman->setSpawnCount(0); //reset spawn count
			myHuman->setHasSpawned(true);

		}//end if

		//set current human to 0 whether breeds or not
		this->setSpawnCount(0);
	}
	else
		this->setSpawnCount(this->getSpawnCount() + 1); //adds to counter.

}//end spawn