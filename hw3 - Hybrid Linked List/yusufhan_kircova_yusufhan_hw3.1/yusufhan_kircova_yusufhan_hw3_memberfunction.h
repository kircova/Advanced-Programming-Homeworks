#ifndef yusufhan_kircova_yusufhan_hw3_memberfunction.h
#define yusufhan_kircova_yusufhan_hw3_memberfunction
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void OpenStudentFile(ifstream & fileStream, string & fileNameInput);
bool CheckCreditNumber(string cardNumber);

struct creditCardNode 
{
	string creditCardNo; creditCardNode * next;
	creditCardNode()
	{
		next = NULL;
	}
};
struct expirationNode 
{ 
	int month, year; creditCardNode * cHead; expirationNode * next; expirationNode * prev;
	expirationNode()
	{
		cHead = NULL;
		next = NULL;
		prev = NULL;
	}
};
class CardList { 
	public: CardList(): head(NULL), tail(NULL){}; //default constructor that creates an empty list 
		void insertCard (expirationNode * node, string creditCardNo); //inserts a new card to the structure in sorted fashion 
		void displayListChronological (); //displays entire structure in chronological order 
		void displayListReverseChronological (); //displays entire structure in reverse chronological order 
		void cardSearch (string creditCardNo); //displays all of the occurrences of the given card number 
		void bulkDelete (int month, int year); //deletes all nodes up to and including given expiration date 
		void deleteAll (); //deletes the entire structure private: expirationNode * head; expirationNode * tail;
		void InsertCreditCard(creditCardNode * & card_node, creditCardNode * credit_head, expirationNode * exp_node);
	private:
		expirationNode * head; 
		expirationNode * tail;

};


#endif