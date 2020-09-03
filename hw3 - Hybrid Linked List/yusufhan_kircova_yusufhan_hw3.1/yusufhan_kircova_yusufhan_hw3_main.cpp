#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "yusufhan_kircova_yusufhan_hw3_memberfunction.h"
using namespace std;


int main()
{
	CardList listObject;
	int menuSelection;
	do
	{
			cout << "1) Upload Card(s) from a File" << endl;
			cout << "2) Display List Chronological" << endl;
			cout << "3) Display List Reverse Chronological" << endl;
			cout << "4) Card Search" << endl;
			cout << "5) Bulk Delete" << endl;
			cout << "6) Exit" << endl;
			cout << "Please choose option from the menu: ";
			if(cin >> menuSelection)
			{
				
				if(menuSelection == 1)
				{
					string fileName;
					ifstream fileStream;
					OpenStudentFile(fileStream, fileName);
					
					string line;
					while (getline(fileStream,line))
					{
						istringstream iss(line);
						string creditCardNumber;
						int month; int year;
						iss >> creditCardNumber >> month >> year;
						expirationNode * tempNode = new expirationNode;
						tempNode->month = month; tempNode->year = year;

						listObject.insertCard(tempNode, creditCardNumber);
					}
				}
				else if(menuSelection == 2)
				{
					listObject.displayListChronological();
				}
				else if(menuSelection == 3)
				{
					listObject.displayListReverseChronological();
				}
				else if(menuSelection  == 4)
				{
					string creditCardNumber;
					cout << "Please enter the credit card number: ";
					cin >> creditCardNumber;
					if(CheckCreditNumber(creditCardNumber))
					{
						listObject.cardSearch(creditCardNumber);
					}
					else
					{
						cout << "Invalid format!" << endl;
					}
				}
				else if(menuSelection  == 5)
				{
					int month, year;
					cout << "Please enter month and year: ";
					if(cin >> month >> year)
					{
						if( month > 12)
						{
							cout << "Invalid format!" << endl;
						}
						else
						{
							listObject.bulkDelete(month,year);
						}
					}
					else
					{
						cout << "Invalid format!" << endl;
						cin.clear();
						cin.seekg(0);
					}
				}
				else if(menuSelection == 6)
				{
					listObject.deleteAll();
				}
				else
				{
					cout << "Invalid operation!" << endl;
				}
			}
			else
			{
				cout << "Invalid format!" << endl;
				cin.clear();
				cin.seekg(0);
			}
	} while (menuSelection != 6);


	cout << "Terminating!!! "  << endl;
			
	
		
	return 1;
}