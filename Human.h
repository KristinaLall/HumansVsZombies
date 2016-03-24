//Human Header file
//Interface for the class Human

#ifndef HUMAN_H
#define HUMAN_H

#include <vector>
#include "Organism.h"
#include "City.h"
using namespace std;

class Human : public Organism //inherits from Organism Class
{
public:
	//Constructor & Destructors
	Human();
	Human(City *city, int width, int height);
	virtual ~Human();

	//Methods Implemented from superclass.
	void move();
	void spawn();
};//end class Human

#endif