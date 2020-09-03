#ifndef BOARDCLASS_H
#define BOARDCLASS_H

#include <string>
using namespace std;

class Board
{
public:
	Board();
	void displayBoard();
	char getOwner(int x, int y);
	void setOwner(int x, int y, char player);
	bool isFull();
	int countOwnedCells(char player);

private:
	char PlayBoard[2][6];
};


#endif