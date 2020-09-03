#ifndef _INTEGERSET_H
#define _INTEGERSET_H
#include <iostream>
#include <istream>
using namespace std;

class IntegerSet
{
private:
	int * list;
	int size;
public:
	IntegerSet();
	IntegerSet(int);
	IntegerSet(const IntegerSet &);
	~IntegerSet();

	 IntegerSet operator+(const IntegerSet &)const;
	 IntegerSet operator*(const IntegerSet &)const;
	 IntegerSet& operator=(const IntegerSet &);
	 IntegerSet& operator+=(IntegerSet &);
	 bool operator!=(IntegerSet &)const;
	 bool operator<=(const IntegerSet &);

	int getSize();
	int * getList();
	void setList(int *);
	void setSize(int);

};

ostream&operator<<(ostream& os, const IntegerSet & Set);
IntegerSet operator+(IntegerSet &, int); 
bool operator<=(int number, const IntegerSet & set);
#endif