#ifndef PLAYERCLASS_h
#define PLAYERCLASS_H

#include "BoardClass.h"
#include <string>
#include <iostream>
using namespace std;

class Player
{
public:
	Player();
	int getCol();
	int getRow();
	bool wins();
	void claimOwnership();
	void move(int);
	//Took from CS204 - Lab 8 
	Player::Player(Board & myboard,char ch, int dir)
		: PlayerBoard(myboard), player(ch), row(0), col(0), direction(dir)
		{ }

private:
	int row;
	int col;
	int direction;
	char player;
	Board & PlayerBoard;
};


#endif