#include <iostream>
#include <sstream>
using namespace std;
unsigned char PFunction(unsigned char plaintext)//Function shifts the bits into their new places
{
	unsigned char num = NULL;
	unsigned char plaintextChar = plaintext & 1;//Increases as power of two, first bit is 2^0
	num = num | (plaintextChar << 2);
	plaintextChar = plaintext & 2;//Second bit is 2^1
	num = num | (plaintextChar >> 1);
	plaintextChar = plaintext & 4;//Third bit is 2^2
	num = num | (plaintextChar << 1);
	plaintextChar = plaintext & 8;//Fourth bit is 2^3
	num = num | (plaintextChar >> 2);
	plaintextChar = plaintext & 16;//Fifth bit is 2^4
	num = num | (plaintextChar << 2);
	plaintextChar = plaintext & 32;//Sixth bit is 2^5
	num = num | (plaintextChar >> 1);
	plaintextChar = plaintext & 64;//Seventh bit is 2^6
	num = num | (plaintextChar << 1);
	plaintextChar = plaintext & 128;//Eigth bit is 2^7
	num = num | (plaintextChar >> 2);
	return num;//Returns the new unsigned char
}
void XORFunction(string input, string key)//Function does the XOR operation and prints the necessary outputs.
{
	unsigned char myChar, encryptedChar;
	int counter = 0;//This counter is used to deal with key index
	for (int i = 0; i < input.size(); i++)
	{
		myChar = input[i];
		encryptedChar = PFunction(myChar) ^ key[counter];//XOR operation between char from P and key's necessary index.
		cout << hex << (int)encryptedChar;//Prints the new char as hex
		counter++;
		if(counter > key.size() - 1)//If key size is lesser than the input size, than program sets counter to zero
			counter = 0;//So that it could start from key's 0th index, therefore key never ends.
	}
	cout << endl << endl;
}
int main()
{
	cout << "*** Welcome to the Simple Data Encryption Application ***" << endl;
	string key, input;
	cout << "Please enter the encryption key: ";
	cin >> key;
	int counter = 0;
	while(getline(cin,input))//getting input as user enters 
	{
		if(counter != 0)//just so the first iteration does not happen
		{
			cout << "Cypher text: ";
			XORFunction(input,key);
		}
		counter ++;
		cout << "Please enter the plaintext to be encrypted:";
	}
}//57 lines for the style points.