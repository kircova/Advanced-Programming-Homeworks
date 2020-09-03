#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "yusufhan_kircova_yusufhan_hw4_memberfunctions.h"
using namespace std;

int main()
{
	string columnInput;
	string rowInput;
	int rowNumber;
	int columnNumber;
	bool IsFalseInput = true;
	bool IsFalseColumnNumber = true;
	while (IsFalseInput)//While loop for input check
	{
		cout << "Enter the number of rows: ";
		cin >> rowInput;
		if(IsNumeric(rowInput))
		{
			rowNumber = stoi(rowInput);
			if(rowNumber >= 3)
			{
				while (IsFalseColumnNumber)
				{
					cout << "Enter the number of columns: ";
					cin >> columnInput;
					if(IsNumeric(columnInput))
					{
						columnNumber = stoi(columnInput);
						if(columnNumber >= 3)
						{
							IsFalseInput = false;
							IsFalseColumnNumber= false;
						}
						else
						{
							cout << columnInput << " is not valid!" << endl;
						}
					}
					else
					{
						cout << columnInput << " is not valid!" << endl;
					}
				}
			}
			else
			{
				cout << rowInput << " is not valid!" << endl;
			}
		}
		else
		{
			cout << rowInput << " is not valid!" << endl;
		}
	}
	ifstream fileStream;
	string fileName;
	OpenStudentFile(fileStream, fileName);//Opens the file

	Matrix2D fileMatrix(rowNumber,columnNumber);
	string line;
	int counter = 0;
	while(getline(fileStream,line))//Writes a matrix from the filestream
	{
		for (int i = 0; i < line.size(); i++)
		{
			fileMatrix.SetIndex(counter, i, line[i]);
		}
		counter ++;
	}
	string xSTD, ySTD;
	int startingRow, startingColumn;
	bool IsFalseRow = false;
	bool IsFalseColumn = false;

	while (!IsFalseRow || !IsFalseColumn)//While loop for input check
	{
		cout << "Enter the starting point: ";
		if(cin >> xSTD)
		{
			if(IsNumeric(xSTD))
			{
				startingRow = stoi(xSTD);
				if(startingRow < rowNumber)
				{
					IsFalseRow = true;
					if(cin >> ySTD)
					{
						if(IsNumeric(ySTD))
						{
							startingColumn = stoi(ySTD);
							if(startingColumn < columnNumber)
							{
								IsFalseColumn = true;
							}
							else
							{
								cout << "Invalid coordinate" << endl;
								cin.clear();
								cin.seekg(0);
							}
						}
						else
						{
							cout << "Invalid coordinate" << endl;
							cin.clear();
							cin.seekg(0);
						}
					}
					else
					{
						cout << "Invalid coordinate! " << endl;
						cin.clear();
						cin.seekg(0);
					}
				}
				else
				{
					cout << "Invalid coordinate! " << endl;
					cin.clear();
					cin.seekg(0);
				}
			}
			else
			{
				cout << "Invalid coordinate! " << endl;
				cin.clear();
				cin.seekg(0);
			}
		}
		else
		{
			cout << "Invalid coordinate! " << endl;
			cin.clear();
			cin.seekg(0);
		}
	}

	if(fileMatrix.GetIndex(startingRow,startingColumn) == ' ')//If the start coordinate is empty
	{
		char fillChar;
		int counter = 0;
		do
		{
			cout << "Enter the filling char: ";
			cin >> fillChar;
			if(fillChar == 'X' || fillChar == 'x')//Checks if the fill char is X or x
			{
				cout << "Filling char is not valid!" << endl;
			}
		} while (fillChar == 'X' || fillChar == 'x');

		DynIntStack VisitedCords;
		bool HasValidNeighbour = true;

		fileMatrix.SetIndex(startingRow, startingColumn, fillChar);
		VisitedCords.push(startingRow, startingColumn);//Pushes the starting coordinate twice.
		VisitedCords.push(startingRow, startingColumn);
		int tempRow = startingRow; int tempCol = startingColumn;

		while (!VisitedCords.isEmpty())
		{
			if(HasValidNeighbour)//If the coordinate has a empty space as neighbour
			{
				if(fileMatrix.GetIndex(tempRow, tempCol + 1) == ' ')//Checks one coordinate right
				{
					tempCol++;
					fileMatrix.SetIndex(tempRow, tempCol, fillChar);//Uses matrix 
					VisitedCords.push(tempRow, tempCol);//Pushes in dynamic stack
				}
				else if(fileMatrix.GetIndex(tempRow + 1, tempCol) == ' ')//Checks one coordinate down
				{
					tempRow++;
					fileMatrix.SetIndex(tempRow, tempCol, fillChar);
					VisitedCords.push(tempRow, tempCol);//Pushes in dynamic stack
				}
				else if(fileMatrix.GetIndex(tempRow, tempCol - 1) == ' ')//Checks one coordinate left
				{
					tempCol--;
					fileMatrix.SetIndex(tempRow, tempCol, fillChar);
					VisitedCords.push(tempRow, tempCol);//Pushes in dynamic stack
				}
				else if(fileMatrix.GetIndex(tempRow - 1, tempCol) == ' ')//Checks one coordinate up
				{
					tempRow--;
					fileMatrix.SetIndex(tempRow, tempCol, fillChar);
					VisitedCords.push(tempRow, tempCol);//Pushes in dynamic stack
				}
				else
				{
					HasValidNeighbour  = false;
				}
			}
			else
			{
				VisitedCords.pop(tempRow,tempCol);//Goes back if the coordinate has no valid coordinates.
				HasValidNeighbour = true;
			}
		}
		fileMatrix.PrintMatrix();
	}
	else
	{
		cout << "Starting point is already occupied. " << endl;
	}

	return 1;
}