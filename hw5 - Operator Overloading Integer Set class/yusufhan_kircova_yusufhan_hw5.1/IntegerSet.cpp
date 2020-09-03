#include "IntegerSet.h"
#include <iostream>
#include <istream>
using namespace std;

IntegerSet::IntegerSet()//Default constructor
{
	size = 0;
	list = NULL;
}
IntegerSet::IntegerSet(int Size)//Constructor which takes size as parameter
{
	size = Size;
	list = new int[size];
	for (int i = 0; i < size; i++)
	{
		list[i] = i;
	}
}
IntegerSet::IntegerSet(const IntegerSet & temp)//Constructorr which takes the copy of the set
{
	size = temp.size;
	list = new int[size];
	for(int i = 0; i < size; i++)
	{
		list[i] = temp.list[i];
	}
}
IntegerSet::~IntegerSet()//Destructor
{
	size = 0;
	delete[] list;
}
int IntegerSet::getSize()//Getting the size
{
	return size;
}
int * IntegerSet::getList()//Getting the list
{
	return list;
}
void IntegerSet::setList(int * temp_list)//Setting the list
{
	list = temp_list;
}
void IntegerSet::setSize(int temp_size)//Seting the size
{
	size = temp_size;
}
IntegerSet operator+ (IntegerSet & set, int number)//+ Operator Overloading 
{
	bool DoesContain = false;
	for (int i = 0; i < set.getSize(); i++)
	{
		if(set.getList()[i] == number)//Checks whether the number is unique
		{
			DoesContain = true;
		}
	}
	if(!DoesContain)//If the number is not found in the array it program goes into this if
	{
		int new_size = set.getSize() + 1;
		int * new_list = new int[new_size];
		for (int i = 0; i < new_size; i++)
		{
			if(i < new_size - 1)//Copies the set, adds the old elements into a new list
			{
				new_list[i] = set.getList()[i];
			}
			else
			{
				new_list[i] = number;//Adds the new number to the list
			}
		}
		IntegerSet newSet = IntegerSet();
		newSet.setList(new_list);
		newSet.setSize(new_size);
		return newSet;
	}
	return set;
}
IntegerSet IntegerSet::operator+(const IntegerSet& set)const//Adds two Integer sets together, joins them into one new set.
{
	IntegerSet newSet(set);

	for (int i = 0; i < size; i++)
	{
		newSet = newSet + list[i];
	}
	return newSet;
}
IntegerSet IntegerSet::operator*(const IntegerSet & set)const//Gets the intercept of the two sets.
{
	IntegerSet newSet;
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < set.size; j++)
		{
			if(list[i] == set.list[j])//If an element is found in the other set
			{
				newSet = newSet + list[i];//Program adds the set into a the final set
				counter++;
			}
		}
	}
	newSet.size = counter;
	return newSet;
}
IntegerSet&IntegerSet::operator=(const IntegerSet & set)//Equates one set to another.
{
	size = set.size;
	int * temp_list = new int[size];
	for (int j = 0; j < size; j++)
	{
		temp_list[j] = set.list[j];//Creating a copy of the set since the user can write something like "set1 = set1"
	}//So that I wouldnt lose set's list

	list = new int[size];
	for (int i = 0; i < size; i++)
	{
		list[i] = temp_list[i];
	}
	return *this;
}
IntegerSet&IntegerSet::operator+=(IntegerSet & set)//Addition operation, this funciton utilizes the previous addition function
{
	IntegerSet newSet = IntegerSet();
	newSet = set + *this;//New set's value become the union of the two sets

	*this = newSet;
	return *this;//Returns the left hand side's new value
}
bool IntegerSet::operator!=(IntegerSet & set)const//Cheks if the sets are equal to each other
{
	int counter = 0;
	if(size == set.size)//If they are not the same size there is no possibility the sets are same
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < set.size; j++)
			{
				if(list[i] == set.list[j])//Increments the counter when the same numbers have been found
				{
					counter++;
				}
			}
		}
		if(counter == size)//If counter is equal to size the sets are equal
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return true;
	}
}
bool operator<=(int number, const IntegerSet & set)//Checks if the left hand side is a subset of the right hand side
{
	bool DoesInclude = false;
	IntegerSet newSet(set);
	for (int i = 0; i < newSet.getSize(); i++)
	{
		if(newSet.getList()[i] == number)
		{
			DoesInclude = true;
		}
	}
	return DoesInclude;
}
bool IntegerSet::operator<=(const IntegerSet & set)//This function utilizes the other <= function, similar progress
{//Function is used to find out if the lfs is a subset of the rhs
	bool IsSubset = true;
	IntegerSet newSet(set);
	if(size <= newSet.getSize())
	{
		for (int i = 0; i < size; i++)
		{
			if( !(list[i] <= newSet))
			{
				IsSubset = false;
			}
		}
	}
	else
	{
		IsSubset = false;
	}
	return IsSubset;
}

ostream&operator<<(ostream& os, const IntegerSet & set)//Prints out the whole sets
{
	IntegerSet temp_set = IntegerSet(set);
	os<< "{";
	for (int i = 0; i < temp_set.getSize(); i++)
	{
		os<< temp_set.getList()[i];
		if(i != temp_set.getSize() - 1)//So that the last one wouldn't print a coma
		{
			cout<< ", ";
		}
	}
	os << "}";
	return os;
}
