#include "BoardClass.h"
#include <iostream>
#include <string>
using namespace std;

Board::Board()//Constructor, sets the initial value of cells as "-"
{
	for (int i = 0; i < 2; i++)//Two loops goes through matrix
	{
		for (int j = 0; j < 6; j++)
		{
			PlayBoard[i][j] = '-';
		}
	}
}

void Board::displayBoard()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << PlayBoard[i][j] << " ";//Prints every element of the matrix
		}
		cout << endl;//Necessary endline, for indicating each row
	}
	cout << endl;
}

char Board::getOwner(int x, int y)
{
	return PlayBoard[x][y];//returns the char for the selected index
}

void Board::setOwner(int x, int y, char owner)
{
	PlayBoard[x][y] = owner;
}

bool Board::isFull()//Goes through each cell
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if(PlayBoard[i][j] == '-')
			{
				return false;//returns false if the cell is vacant
			}
		}
	}
	return true;
}

int Board::countOwnedCells(char player)//Returns the value of owned cells by each player
{
	int counter = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if(PlayBoard[i][j] == player)
			{
				counter++;
			}
		}
	}
	return counter;
}
