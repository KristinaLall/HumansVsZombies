#ifndef _GAMESPECS_H
#define _GAMESPECS_H


const int GRID_HEIGHT = 20; // size of the square grid
const int GRID_WIDTH = 20; // size of the square grid
const int HUMAN_STARTCOUNT = 100; // inital Humans
const int ZOMBIE_STARTCOUNT = 5; //initial Zombie count
const int HUMAN_BREED = 3; // steps until an Human breeds
const int ZOMBIE_BREED = 8; // steps until an Zombie breeds
const int ZOMBIE_STARVE = 3; // steps until a Zombie starves and converts back
const double PAUSE_SECONDS = .09; // pause between steps


//Colors
//0  = black				//9  = bright blue
//1  = blue					//10 = bright green
//2  = green				//11 = bright turquoise
//3  = turquise				//12 = bright red
//4  = red					//13 = bright pink
//5  = pink					//14 = bright yellow
//6  = yellow				//15 = bright white
//7  = white regular		//16+ = solid blocks
//8  = white pale

const int HUMAN_COLOR = 3; // turquoise
const int ZOMBIE_COLOR = 14; // bright yellow
const int BOARD_COLOR = 7; //white

#endif