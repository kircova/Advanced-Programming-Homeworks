#include <iostream>
#include <string>
#include "PlayerClass.h"
#include "BoardClass.h"

using namespace std;

int Player::getCol()
{
	return col;
}
int Player::getRow()
{
	return row;
}
bool Player::wins()
{
	if(PlayerBoard.countOwnedCells(player) >= 7)//If Owned cells are bigger than 7, the player wins
	{
		return true;
	}
	return false;
}
void Player::claimOwnership()
{
	if(PlayerBoard.getOwner(row,col) == '-')//If cell is empty
	{
		PlayerBoard.setOwner(row, col, player);//New owner is setted
	}
}

void Player::move(int moves)//4 cases to watch out, 2 for clockwise and 2 for counter clockwise
{
	if(direction == 0)//Counter clockwise 
	{
		for (int i = 0; i < moves; i++)
		{
			if(row == 0)
			{
				if(col == 0)//(0,0) is a turning point for counterclock wise
				{
					row ++;//It goes one cell up
				}
				else
				{
					col--;
				}
			}
			else //(row == 1)
			{
				if(col == 5)//(1,5) is a turning point for counterclockwise
				{
					row --;//One cell down
				}
				else
				{
					col++;
				}
			}
		}
	}
	else if(direction == 1)//clockwise
	{
		for (int i = 0; i < moves; i++)
		{
			if(row == 0)
			{
				if(col == 5)//(0,5) is a turning point for clockwise
				{
					row ++;//Goes one cell down
				}
				else
				{
					col ++;
				}
			}
			else //(row == 1)
			{
				if(col == 0)//(1,0) is a turning point for clockwise
				{
					row --;//One cell up
				}
				else
				{
					col --;
				}
			}
		}
	}
}

