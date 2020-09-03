#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
	expirationNode temp_node = node;
	if(temp_node.cHead == NULL)
	{
		creditCardNode * cNode; 
		cNode->creditCardNo = creditCardNo;
		temp_node.cHead = cNode;
	}
	else
	{
		
	}
struct node
{
	int id;
	int month, year;
	vector<string> cards;
	node * next;
};
void InsertSorted(node*& head_ref, node* new_node, node*& tail)//Function inserts a new node to the list with respect to its date
{ 
	node* current =  head_ref;
	if (head_ref == NULL || ((head_ref)->month > new_node->month && (head_ref)->year == new_node->year) || (head_ref)->year > new_node->year ) 
    { //If checkes if the head is empty or head's date is bigger than the new node's date.
        new_node->next = head_ref; //Changes the head if thats the case.Swaps.
        head_ref = new_node; 
    } 
    else
    { 
        current = head_ref; 
		while (current->next != NULL &&  (current->next->year < new_node->year || (current->next->year == new_node->year && current->next->month < new_node->month)))
        { //checks the rest of the list if the new node is bigger than the iterated node
			if(current->next!= NULL)
				current = current->next; 
        } 
		if (current->next == NULL)
		{
			new_node->next = current->next; //Incrementing setting the new head
			current->next = new_node; 
			tail = new_node;
		}
        new_node->next = current->next; //Iterating nodes
        current->next = new_node; 
    }
} 
void OpenStudentFile(ifstream & fileStream, string & fileNameInput)//Function opens the file and sets the value of filestream.
{
	string fileName;
	cout << "Please enter file name: ";
	cin >> fileName;
	fileStream.open(fileName.c_str());
	while(fileStream.fail())//Checks if the file is openable, if not continously asks for new input.
	{
		cout << "Cannot find a file named "<< fileName << endl;
		cout << "Please enter file name: ";
		cin >> fileName;
		fileStream.open(fileName.c_str());
	}
	fileNameInput = fileName;
}
* Begin: Updated code taken from linkedList.cpp */
void PrintList(node *nodePtr)//Prints the whole linked list
{
	if(nodePtr == NULL)
	{
		cout << "List is empty! " << endl;
	}
	else
	{
		while (nodePtr != NULL)
		{
				cout<<"Expiration Date: "<< nodePtr->month << " " << nodePtr -> year << " " << endl;
				for (int i = 0; i < nodePtr->cards.size(); i++)
				{
					cout << (i + 1) << ") " << nodePtr->cards[i] << endl;
				}
				cout << "-------------------" << endl;
			nodePtr = nodePtr->next;
		}
	}
}
* End: Updated code taken from linkedList.cpp */

* Begin: Updated code taken from linkedList.cpp */
void DeleteOneNode (node * toBeDeleted, node * & head)
{
	node * ptr;
	if (toBeDeleted == head)
	{
		ptr = head->next;
		delete toBeDeleted;
		head = ptr;
	}
	else 
	{
		ptr = head;
		while (ptr->next != toBeDeleted)
			ptr = ptr->next;
		ptr->next = toBeDeleted->next;
		delete toBeDeleted;
	}
}
* End: Updated code taken from linkedList.cpp */

void DeleteNode(node * & head, int month, int year)//Used to delete every node with the same condition, which is date.
{
	node* temp = head;
	node * ptr;
	while (temp != NULL)
	{
		if(temp-> month == month && temp->year == year)//Checks for the same dates.
		{
			cout << "Node with expiration date "<< month << " " << year << " and the following credit cards have been deleted! " << endl;
			for (int i = 0; i < temp->cards.size(); i++)
			{
				cout << (i + 1) << ") " << temp->cards[i] << endl;
			}
			DeleteOneNode(temp, head);//Deletes the ones with input date.
			return;
		}
		temp = temp->next;//Incrementing the node so list would iterate
	}
}
* Begin: Updated code taken from linkedList.cpp */
bool SearchList(node *head, int month, int year, string cardNumber)
{
	while (head != NULL)
	{
		if(head-> month == month && head->year == year)
		{
			head->cards.push_back(cardNumber);
			cout << "Node with expiration date " << month << " " <<  year << " already exists"<< endl;
			cout << "Credit card " << cardNumber << " added to node " << month << " " << year << endl;
			cout << "***************" << endl;
			return true;
		}
		head = head->next;
	}
	return false;
}
* End: Updated code taken from linkedList.cpp */

* Begin: code taken from linkedList.cpp */
bool SearchDate(node* head, int month, int year)
{
		while (head != NULL)
		{
		if(head-> month == month && head->year == year)
		{
			return true;
		}
		head = head->next;
		}
	return false;
}
* End: code taken from linkedList.cpp */

* Begin: code taken from linkedList.cpp */
void ClearList(node *head)
{
	node *ptr;
	while(head!=NULL)
	{
		ptr=head;
		head=head->next;
		delete ptr;
	}
}
* End: Updated code taken from linkedList.cpp */

bool SearchCreditNumber(node *head, string cardNumber)//Function compares the inputted card number and the one in the linked lists.
{
	bool DoesContain = false;
	while(head != NULL)
	{
		for (int i = 0; i < head->cards.size(); i++)
		{
			if(head->cards[i] == cardNumber)
			{
				cout << "There exists a credit card given number " << cardNumber << " with expiration date: " << endl;
				cout << head->month << " " << head ->year << endl;
				DoesContain = true;
			}
		}
		head = head->next;
	}
	return DoesContain;
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
int main()
{
	ifstream fileStream;
	string fileName;
	OpenStudentFile(fileStream, fileName);
	string line;
	int counter = 1;
	node * head  = new node(); head = NULL;
	node * tail = new node(); tail = NULL;

	while(getline(fileStream,line))
	{
		istringstream iss(line);
		string cardNumber;
		int month;
		int year;
		iss >> cardNumber >> month >> year;//Each lines month and year is read into their variables.

		node * p_newNode = new node();//My new node
		p_newNode ->cards.push_back(cardNumber);
		p_newNode ->month = month;
		p_newNode ->year = year;
		
		if(head == NULL)//If theres no elemnent, we create the linked list, define the head and tail.
		{
			head = p_newNode;
			cout << "New node is created with expiration date: " << p_newNode->month << " " << p_newNode->year << endl;
			cout << "Credit card " << p_newNode->cards[0] << " added to node " << p_newNode->month << " " << p_newNode->year << endl;
			cout << "***************"<< endl;
			tail = p_newNode;//Since head and tail would be same with one node.
		}
		else
		{
			tail ->next= NULL;//So there is always a new node to check
			if(!SearchList(head, month, year, cardNumber))//If linked list doesnt have a element with the same date goes into this if.
			{
				cout << "New node is created with expiration date: " << p_newNode->month << " " << p_newNode->year << endl;
				cout << "Credit card " << p_newNode->cards[0] << " added to node " << p_newNode->month << " " << p_newNode->year << endl;
				cout << "***************"<< endl;
				InsertSorted( head, p_newNode, tail);//Inserting the new node.
			}
		}
	}
	string input;
	bool ShouldDisplayOptions = true;
	do
	{
		if(ShouldDisplayOptions)
		{
			cout << endl <<"1)Display List" << endl << "2)Card Search via Credit Number" 
			<< endl << "3)Delete Card with respect to Expiration Date" << endl <<"4)Exit" << endl;
			cout << "Please choose option from the menu: ";
		}
		cin >> input;
		if(input == "1")//Prints the whole linked list
		{
			ShouldDisplayOptions = true;
			PrintList(head);
		}
		else if(input == "2")//checks if credit card exists.
		{
			ShouldDisplayOptions = true;
			string creditNumber;
			do
			{
				cout << "Please enter the credit card number: ";
				cin >> creditNumber;
				if(!CheckCreditNumber(creditNumber))
				{
					cout << "Invalid format!" << endl;
				}
			} while (!CheckCreditNumber(creditNumber));

			if(!SearchCreditNumber(head, creditNumber))
			{
				cout << "There is no credit card with given credit card number: " << endl << creditNumber << endl;
			}
		}
		else if(input == "3")//Used to delete a node.
		{
			ShouldDisplayOptions = true;
			int month, year;
			do
			{
				cin.clear();//Clearing the error flags after it iterates, so it wouldn't break the loop.
				cin.seekg(0);
				cout << "Please enter month and year: ";
				if(cin>>month>>year)//Month and year must be integers.
				{
					if(month > 12)//Since more than 12 would be invalid input.
					{
						cout << "Invalid Date!" << endl;
					}
					else
					{
						if(SearchDate(head, month, year))
						{
							DeleteNode(head, month, year);
						}
						else
						{
							cout << "There is no node with expiration date " << month << " " << year << ", nothing deleted!" << endl;
						}
					}
				}
				else
				{
					cout << "Invalid Date!" << endl;
				}
			} while (cin.fail() || month > 12);
		}
		else if(input == "4")
		{
			ShouldDisplayOptions = true;
			ClearList(head);//Clearing the whole list.
		}
		else
		{
			cout << "Invalid format!" << endl;
			cout << "Please choose option from the menu: ";
			ShouldDisplayOptions = false;
		}
	}while (input != "4");

	cout << "Terminating!!" << endl;

	return 1;
}