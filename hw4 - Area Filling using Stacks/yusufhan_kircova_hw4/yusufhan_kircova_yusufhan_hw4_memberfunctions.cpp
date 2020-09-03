#include "yusufhan_kircova_yusufhan_hw4_memberfunctions.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void OpenStudentFile(ifstream & fileStream, string & fileNameInput)//Function opens the file and sets the value of filestream.
{
	int counter = 0;
	string fileName;
	do
	{
		cout << "Please enter file name: ";
		cin >> fileName;
		fileStream.open(fileName.c_str());
		if(fileStream.fail())
			cout << "Cannot open a file named " << fileName << endl;
	} while (fileStream.fail());

	fileNameInput = fileName;
}
bool IsNumeric(string input)//Checks if the string consists of only numbers
{
	for (int i = 0; i < input.length(); i++)
	{
		if(!(input[i] >= 48 && input[i] <= 57))
		{
			return false;
		}
	}	
	return true;
}

/* Begin: code taken from matrixclass.cpp*/
Matrix2D::Matrix2D(int r, int c)
{
	rows=r;
	cols=c;
	data = new char* [r]; 

	for (int i = 0; i<rows; i++) 
		data[i] = new char[cols];		
}
int Matrix2D::GetIndex(int i, int j)
{
	return data[i][j];
}
void Matrix2D::SetIndex(int i, int j, char value)
{
	data[i][j] = value;
}
void Matrix2D::PrintMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << data[i][j];
		}
		cout << endl;
	}
}
/* End: code taken from matrixclass.cpp*/
Matrix2D::~Matrix2D()
{
	for (int i = 0; i < rows; i++)
	{
		delete data[i];
	}
	delete data;
}


/* Begin: code taken from DynIntStack.cpp*/
DynIntStack::DynIntStack()
{
	top = NULL; 
}
void DynIntStack::push(int row, int column)
{
	StackNode *newNode;
	// Allocate a new node & store Num
	newNode = new StackNode;
	newNode->row = row;
	newNode->column = column;

	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = NULL;
	}
	else	// Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
}
void DynIntStack::pop(int &row, int &column)
{
	StackNode *temp;

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else	// pop value off top of stack
	{
		row = top->row;
		column = top->column;
		temp = top->next;
		delete top;
		top = temp;
	}
}
bool DynIntStack::isEmpty(void)
{
	bool status;
	if (top == NULL)
		status = true;
	else
		status = false;

	return status;
}
DynIntStack::~DynIntStack()
{
	StackNode* temp;
	temp = top;
	while(temp != nullptr)
	{
		temp = top->next;
		delete top;
		top = temp;
	}
}
/* End: code taken from DynIntStack.cpp*/
