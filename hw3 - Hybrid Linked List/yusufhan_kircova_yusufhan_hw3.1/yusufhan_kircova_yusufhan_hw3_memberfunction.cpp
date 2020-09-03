#include "yusufhan_kircova_yusufhan_hw3_memberfunction.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
void OpenStudentFile(ifstream & fileStream, string & fileNameInput)//Function opens the file and sets the value of filestream.
{
	string fileName;
	cout << "Please enter file name: ";
	cin >> fileName;
	fileStream.open(fileName.c_str());
	if(fileStream.fail())//Checks if the file is openable, if not continously asks for new input.
	{
		cout << "Could not find a file named "<< fileName << endl;
	}
	fileNameInput = fileName;
}
void CardList::InsertCreditCard(creditCardNode * & c_head, creditCardNode * new_node, expirationNode * exp_node)
{
	creditCardNode *  ptr = c_head;
	if (c_head == NULL || new_node->creditCardNo < c_head->creditCardNo)        
	{   
		bool erroFlag = true;
		if(c_head != NULL)
		{
			erroFlag = false;
			cout << new_node->creditCardNo << " " << exp_node->month << " " << exp_node->year << ": inserted to an existing expiration date node" << endl;
		}
		new_node->next = c_head;
		c_head = new_node;
		if(erroFlag)
			cout << new_node->creditCardNo << " " << exp_node->month << " " << exp_node->year << ": added to a new expiration date node" << endl;
		return;
	}
	while (ptr->next != NULL && ptr->next->creditCardNo <= new_node->creditCardNo)
	{    
		ptr = ptr->next;
	}
	if(ptr != NULL &&(new_node->creditCardNo == ptr->creditCardNo))
	{
		cout << new_node->creditCardNo << " " << exp_node->month << " " << exp_node->year << ": this card was already inserted" << endl;
		return;
	}
	cout << new_node->creditCardNo << " " << exp_node->month << " " << exp_node->year << ": inserted to an existing expiration date node" << endl;
	new_node->next = ptr->next;
	ptr->next = new_node;
	return;
}
void CardList::insertCard(expirationNode * new_node, string creditCardNu)//Function inserts a new node to the list with respect to its date
{
	expirationNode * current = head;
	expirationNode * previous = head;
	creditCardNode * newc_node = new creditCardNode;
	newc_node->creditCardNo = creditCardNu;

	if(head == NULL)//Listede eleman yoksa
	{
		head = new_node;
		tail = new_node;
		InsertCreditCard(new_node->cHead, newc_node, new_node);
	}
	else
	{
		if(current->year > new_node->year || (current->year == new_node->year && current->month > new_node->month))//Listedeki ilk eleman yeni elemandan büyükse
		{
			new_node ->next = head;
			new_node ->prev = NULL;
			head->prev = new_node;
			head = new_node;
			InsertCreditCard(new_node->cHead, newc_node, new_node);
		}
		else
		{
			while(current->next != NULL && ((current-> year < new_node->year || (current->year == new_node->year && current->month < new_node->month))))
			{
				current = current->next;
			}
			if(current->year > new_node->year || (current->year == new_node->year && current->month > new_node->month))
			{
				new_node->next = current;
				new_node->prev = current->prev;
				current->prev->next = new_node;
				current->prev = new_node;
				InsertCreditCard(new_node->cHead, newc_node, new_node);

				return;
			}
			else if(current->year == new_node->year && current->month == new_node->month)
			{
				InsertCreditCard(current->cHead, newc_node, new_node);
				return;
			}
			else if(current->next == NULL && current != head)//Listenin son elemanı
			{
				current->next = new_node;
				new_node->prev = current;
				new_node->next = NULL;
				tail = new_node;
				InsertCreditCard(new_node ->cHead, newc_node, new_node);
				return;
			}
		}
	}
}
void CardList::displayListChronological()
{
	expirationNode * exp_node = head;
	if(exp_node == NULL)
	{
		cout << endl <<"List is empty! " << endl;
	}
	else
	{
		while (exp_node != NULL)
		{
			cout<<"Expiration Date: "<< exp_node->month << " " << exp_node -> year << " " << endl;
			int counter  = 1;

			creditCardNode * copyc_head = exp_node->cHead;
			while (copyc_head != NULL)
			{
				cout << counter << ") " << copyc_head->creditCardNo << endl;

				copyc_head = copyc_head->next;
				counter ++;
			}
			cout << "-------------------" << endl;

			if(exp_node->next == NULL)
				return;
			else
				exp_node = exp_node->next;
		}
	}
}
void CardList::displayListReverseChronological()
{
	expirationNode * exp_node = tail;
	if(exp_node == NULL)
	{
		cout << endl << "List is empty! " << endl;
	}
	else
	{
		while (exp_node != NULL)
		{
			cout<<"Expiration Date: "<< exp_node->month << " " << exp_node -> year << " " << endl;
			int counter  = 1;
			creditCardNode * copyc_head = exp_node->cHead;
			while (copyc_head != NULL)
			{
				cout << counter << ") " << copyc_head->creditCardNo << endl;

				copyc_head =copyc_head->next;
				counter ++;
			}
			cout << "-------------------" << endl;

			if(exp_node->prev == NULL)
				return;
			else
				exp_node = exp_node->prev;
		}
	}
}
void CardList::cardSearch(string creditCardNumber)
{
	int counter = 0;
	expirationNode * exp_node = head;
	while (exp_node != NULL)
	{
		creditCardNode * copyc_head = exp_node->cHead;
		while (copyc_head != NULL)
		{
			if(creditCardNumber == copyc_head->creditCardNo)
			{
				counter ++;
				cout << "There exists a credit card given number " << creditCardNumber <<  " with expiration date: " << exp_node->month << " " << exp_node->year << endl;
			}
			copyc_head = copyc_head->next;
		}

		if(exp_node->next == NULL)
		{
			if(counter == 0)
			{
				cout << "There is no credit card with given credit card number: " << creditCardNumber << endl;
			}
			return;
		}
		else
		{
			exp_node = exp_node->next;
		}
	}
	if(counter == 0)
	{
		cout << "There is no credit card with given credit card number: " << creditCardNumber << endl;
	}
}
bool CheckCreditNumber(string cardNumber)//Function checks the validity of creditCardNumber, returns true if valid.
{
	bool IsValid = true;
	if(cardNumber.length() == 16)//If it consists of 16 digits
	{
		for (int i = 0; i < cardNumber.length(); i++)
		{
			if(cardNumber[i] < 48 || cardNumber[i] > 57)//Comparing the ascii values to check whether all the char's are numbers.
			{
				IsValid = false;
			}
		}
	}
	else
		IsValid = false;

	return IsValid;
}
void CardList::bulkDelete(int month, int year)
{
	expirationNode * current = head;
	if(current == NULL)
	{
		cout << endl <<"List is empty! " << endl;
	}
	else
	{
		while (current != NULL)
		{
			if((current->month <= month && current->year == year)||(current->year < year))
			{
				cout << "Node with expiration date " << current->month << " " << current->year << " and the following credit cards have been deleted!" << endl;
				int counter = 1;

				while (current->cHead != NULL)
				{
					cout << counter << ") " << current->cHead->creditCardNo << endl;

					creditCardNode * temp = new creditCardNode;
					temp = NULL;

					if(current->cHead->next != NULL)
						temp = current->cHead->next;

					delete(current->cHead);
					current->cHead = temp;
					counter ++;
				}

				expirationNode * tempexp = new expirationNode;
				tempexp = NULL;
				if(current ->next != NULL)
					tempexp = current->next;

				delete(current);
				current = tempexp;
			}
			else
			{
				head = current;
				head->prev = NULL;
				return;
			}
		}
		if(current == NULL)
		{
			head =current;
			tail =current;
			return;
		}
	}
}
void CardList::deleteAll()
{
	expirationNode * exp_node = head;
	while (exp_node != NULL)
	{
		creditCardNode * cp_node = exp_node->cHead;
		while (cp_node != NULL)
		{
			creditCardNode * temp = new creditCardNode;
			temp = NULL;

			if(cp_node->next != NULL)
				temp = cp_node->next;

			delete(cp_node);
			cp_node = temp;
		}
		expirationNode * tempexp = new expirationNode;
		tempexp = NULL;
		if(exp_node ->next != NULL)
			tempexp = exp_node->next;

		delete(exp_node);
		exp_node = tempexp;
	}
	cout << "All the nodes have been deleted! " << endl;
}