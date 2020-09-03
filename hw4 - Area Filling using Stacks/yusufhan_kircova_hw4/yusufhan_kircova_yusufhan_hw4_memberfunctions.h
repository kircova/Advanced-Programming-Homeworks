#ifndef yusufhan_kircova_yusufhan_hw4_memberfunctions.h
#define yusufhan_kircova_yusufhan_hw4_memberfunctions
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void OpenStudentFile(ifstream & fileStream, string & fileNameInput);
bool IsNumeric(string input);

/* Begin: code taken from matrixclass.h*/
class Matrix2D {
private: 
	int rows, cols;
	char ** data;
public:
	Matrix2D(int r, int c);
	int GetIndex(int i, int j);
	void SetIndex(int i, int j, char val);
	void PrintMatrix();
	~Matrix2D();
};
/* End: code taken from matrixclass.h */

/* Begin: code taken from DynIntStack.h*/
struct StackNode
{
	int row,column;
	StackNode *next;
};
class DynIntStack
{
private:
	StackNode *top;

public:
	DynIntStack(void);
	void push(int,int);
	void pop(int &, int &);
	bool isEmpty(void);
	~DynIntStack();
};
/* End: code taken from matrixclass.h */
#endif