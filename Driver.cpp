//This is the Driver file for the program

#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <Windows.h>
#include "City.h"
#include "Human.h"
#include "Organism.h"
#include "Zombie.h"
using namespace std;



//Reference for colors: http://www.cplusplus.com/forum/beginner/5830/
//Reference for Timer: http://www.cplusplus.com/reference/ctime/clock/


int numberOfHumans = 0;
int numberOfZombies = 0;
int iterations = 0;
City *city = new City();
HANDLE  color = GetStdHandle(STD_OUTPUT_HANDLE);

 void runTurnStep()
{
	city->move();
	numberOfHumans = city->numberOfHumans();
	numberOfZombies = city->numberOfZombies();
	iterations++;

	//Draw The city
	cout << *city;
	//cout << "-----------------------------------------" << endl;
	cout << endl;
	SetConsoleTextAttribute(color, 7);//white
	cout << "     Iterations: " << iterations;
	SetConsoleTextAttribute(color, HUMAN_COLOR);//turquoise
	cout << "  Humans: " << numberOfHumans;
	SetConsoleTextAttribute(color, ZOMBIE_COLOR);//yellow
	cout << "  Zombies: " << numberOfZombies << "       " << endl;
	SetConsoleTextAttribute(color, BOARD_COLOR);

}//end runTurnStep
		 


int main()
{
	//random generator
	srand(time(NULL)); //new seed

	//Populate the City with Humans
	do{
		int ranX = rand() % GRID_WIDTH;
		int ranY = rand() % GRID_HEIGHT;
		int randomSpawn = rand() % 4;

		if (city->getOrganism(ranX, ranY) == NULL){
			//create and set human
			Human *myHuman = new Human(city, GRID_WIDTH, GRID_HEIGHT);
			myHuman->setPosition(ranX, ranY);
			myHuman->setSpawnCount(randomSpawn);
			city->setOrganism(myHuman, ranX, ranY);
			numberOfHumans++;
		}

	} while (numberOfHumans < HUMAN_STARTCOUNT);

	//Populate the city with Zombies
	do{
		int ranX = rand() % GRID_WIDTH;
		int ranY = rand() % GRID_HEIGHT;
		int randomSpawn = rand() % 9;

		if (city->getOrganism(ranX, ranY) == NULL){
			//create and set zombie
			Zombie *myZombie = new Zombie(city, GRID_WIDTH, GRID_HEIGHT);
			myZombie->setPosition(ranX, ranY);
			myZombie->setSpawnCount(randomSpawn);
			city->setOrganism(myZombie, ranX, ranY);
			numberOfZombies++;
		}

	} while (numberOfZombies < ZOMBIE_STARTCOUNT);

	while (numberOfHumans > 0 && numberOfZombies > 0)
	{
		runTurnStep();

		//Uses a timer to iterate through steps
	/*	clock_t start_time = clock();
		clock_t end_time = PAUSE_SECONDS * 1000 + start_time;
		while (clock() < end_time);*/
	}
	
	//Output the Winner
	if (numberOfHumans > 0) { cout << "     Humans Win!"; }
	else { cout << "     Zombies Win!"; }

	_getch();
	return 0;
}
