//Zombie Header file
//Interface for the class Zombie

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <vector>
#include "Organism.h"
#include "City.h"
using namespace std;

class Zombie : public Organism //inherits from Organism Class
{
protected:
	//Variables
	int starve;

public:
	//Constructors & Destructor
	Zombie();
	Zombie(City *city, int width, int height);
	virtual ~Zombie();

	//Methods inherited from super class
	void move();
	void spawn();

	//Getters and Setters
	int getStarve();
	void setStarve(int eat);

	//Methods
	void starveZombie();

};//end class Zombie

#endif