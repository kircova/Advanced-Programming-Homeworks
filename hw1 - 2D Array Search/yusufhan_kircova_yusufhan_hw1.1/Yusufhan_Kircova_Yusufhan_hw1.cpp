//#include <string>
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//using namespace std;
////Yusufhan Kircova 26678
////--------------------
////This struct is used to store both x and y coordinates in the same vector.
//struct Coordinate
//{
//	int x;
//	int y;
//};
////--------------------------------
////This function is used to open the file if possible, if not program prints the necessary output.
//void OpenStudentFile(ifstream & fileStream, string & fileNameInput)
//{
//	string fileName;
//	cout << "Please enter file name: ";
//	cin >> fileName;
//	fileStream.open(fileName.c_str());
//	while(fileStream.fail())//Checks if the file is openable, if not continously asks for new input.
//	{
//		cout << "Cannot find a file named "<< fileName << endl;
//		cout << "Please enter file name: ";
//		cin >> fileName;
//		fileStream.open(fileName.c_str());
//	}
//	fileNameInput = fileName;
//}
////---------------------------------
////This function is used to print the matrix as output, in a matrix form.
//void PrintMatrix(vector<vector<char>> matrix)
//{
//	for (int i = 0; i < matrix.size(); i++)
//	{
//		for (int j = 0; j < matrix[0].size(); j++)
//		{
//			cout << matrix[i][j];
//		}
//		cout << endl;//When row number is increased, program prints an endl.
//	}
//}
////----------------------------------
////This function checks if the given matrix is a valid matrix, returns true if it is valid, else returns false.
//bool CheckMatrix(vector<vector<char>> matrix, string fileName)
//{
//	bool correctSize = true;
//	for (int i = 0; i < matrix.size(); i++)//Checking the size of each row.
//	{
//		int vectorSize = matrix[0].size();
//		if(vectorSize != matrix[i].size())
//		{
//			correctSize = false;
//		}
//	}
//	if(correctSize)//If my size is correct.
//	{
//		bool correctCharacter = true;
//		for (int i = 0; i < matrix.size(); i++)//These two loops goes and checks each charactrer of the matrix.
//		{
//			for (int j = 0; j < matrix[0].size(); j++)
//			{
//				if(matrix[i][j] != 'x' && matrix[i][j] != 'o')
//				{
//					correctCharacter = false;
//				}
//			}
//		}
//		if (!correctCharacter)//Looks for invalid characters.
//		{
//			cout << fileName << " includes invalid char(s)" << endl;
//			return false;
//		}
//	}
//	else//If my size of rows are not equal
//	{
//		cout << fileName <<" is invalid matrix, does not contain same amount of char each row!" << endl;
//		return false;
//	}
//	return true;
//}
////--------------------------------------------------
////This is a recursive function which looks for closed areas, Prints the path and necessary outputs.
//void CheckClosedArea(vector<vector<char>> matrix, int & rowX, int & columnY, vector<vector<char>> & visistedCoordinates, vector<Coordinate> & printCoordinate, int CONSrowX, int CONcolumnY, bool & end)
//{
//	//Check if the first cell which is right to our initial coordinate is occupied or not.
//	if(columnY != matrix[0].size() - 1 && matrix[rowX][columnY + 1] == 'x' && visistedCoordinates[rowX][columnY + 1] != '1' && end == false )
//	{
//		visistedCoordinates[rowX][columnY + 1] = '1';//This matrix is a copy of the inputted matrix, but empty. As the program looks for enclosed areas, program marks the coordinates in this copy matrix to determine if it visited or not.
//		columnY = columnY + 1;
//
//		Coordinate xy; xy.x = rowX; xy.y = columnY;;
//		printCoordinate.push_back(xy);//print Coordinate is a vector of coordinate, program adds the  visited coordinates.
//
//		CheckClosedArea(matrix, rowX, columnY, visistedCoordinates, printCoordinate, CONSrowX, CONcolumnY, end);//Recursive structure continues till the loop breaks. Which only occurs in the last two else if statements
//	}
//	//Checks the next down cell is occupied or not.
//	else if (rowX != matrix.size() - 1 && matrix[rowX + 1][columnY] == 'x' && visistedCoordinates[rowX + 1][columnY] != '1' && end == false )
//	{
//		visistedCoordinates[rowX + 1][columnY] = '1';
//		rowX = rowX + 1;
//
//		Coordinate xy; xy.x = rowX; xy.y = columnY;;
//		printCoordinate.push_back(xy);
//		
//		CheckClosedArea(matrix, rowX, columnY, visistedCoordinates, printCoordinate, CONSrowX, CONcolumnY, end);
//	}
//	//checks the next left cell is occupied or not.
//	else if(columnY != 0 && matrix[rowX][columnY - 1] == 'x' && visistedCoordinates[rowX][columnY - 1] != '1' && end == false )
//	{
//		visistedCoordinates[rowX][columnY - 1] = '1';
//		columnY = columnY - 1;
//
//		Coordinate xy; xy.x = rowX; xy.y = columnY;
//		printCoordinate.push_back(xy);
//
//		CheckClosedArea(matrix, rowX, columnY, visistedCoordinates, printCoordinate, CONSrowX, CONcolumnY, end);
//	}
//	//Checks the next up cell is occupied or not.
//	else if(rowX != 0 && matrix[rowX- 1][columnY] == 'x' && visistedCoordinates[rowX - 1][columnY] != '1' && end == false)
//	{
//		visistedCoordinates[rowX - 1][columnY] = '1';
//		rowX = rowX -1;
//
//		Coordinate xy; xy.x = rowX; xy.y = columnY;
//		printCoordinate.push_back(xy);
//		
//		CheckClosedArea(matrix, rowX, columnY, visistedCoordinates, printCoordinate, CONSrowX, CONcolumnY, end);
//	}//---------------------------------------------------------------------------------------------------------
//	//Checks if the next right cell is the begining coordinate.
//	else if(rowX == CONSrowX && columnY + 1 == CONcolumnY && end == false && matrix[rowX][columnY + 1] == 'x')
//	{
//		columnY = columnY + 1;
//		Coordinate xy; xy.x = rowX; xy.y = columnY ;
//		printCoordinate.push_back(xy);
//		end = true;
//		CheckClosedArea(matrix, rowX, columnY, visistedCoordinates, printCoordinate, CONSrowX, CONcolumnY, end);
//	}
//	//Checks if the next down cell is the begining coordinate.
//	else if(rowX + 1 == CONSrowX && columnY == CONcolumnY && end == false && matrix[rowX + 1][columnY] == 'x')
//	{
//		rowX = rowX + 1;
//		Coordinate xy; xy.x = rowX ; xy.y = columnY;
//		printCoordinate.push_back(xy);
//		end = true;
//		CheckClosedArea(matrix, rowX, columnY, visistedCoordinates, printCoordinate, CONSrowX, CONcolumnY, end);
//	}
//	//Checks if the next left cell is the begining coordinate.
//	else if(rowX == CONSrowX && columnY - 1 == CONcolumnY && end == false && matrix[rowX][columnY -1] == 'x')
//	{
//		columnY = columnY -1;
//		Coordinate xy; xy.x = rowX; xy.y = columnY;
//		printCoordinate.push_back(xy);
//		end = true;
//		CheckClosedArea(matrix, rowX, columnY, visistedCoordinates, printCoordinate, CONSrowX, CONcolumnY, end);
//	}
//	//Checks if the next up cell is the begining coordinate.
//	else if(rowX - 1 == CONSrowX && columnY  == CONcolumnY && end == false && matrix[rowX -1][columnY] == 'x')
//	{
//		rowX = rowX -1;
//		Coordinate xy; xy.x = rowX  ; xy.y = columnY;
//		printCoordinate.push_back(xy);
//		end = true;
//		CheckClosedArea(matrix, rowX, columnY, visistedCoordinates, printCoordinate, CONSrowX, CONcolumnY, end);
//	}
//	//If the begining coordinate is the equal to end coordinate and if the program visited more than 3 points(Since it would take more than 3 points to create a closed space)
//	else if(rowX == CONSrowX && columnY == CONcolumnY && printCoordinate.size() > 3)
//	{
//		cout << "Found an enclosed area. The coordinates of the followed path: " << endl;
//		for (int i = 0; i < printCoordinate.size(); i++)
//		{
//			if(i != printCoordinate.size() - 1)
//			{
//				cout << printCoordinate[i].x << " " << printCoordinate[i].y << endl;
//			}
//		}
//	}
//	//If it fails to go to a cell or to its first coordinate, program can not find a enclosed area.
//	else
//	{
//		cout << "Cannot found an enclosed area starting with given coordinate. The coordinates of the followed path: " << endl;
//		for (int i = 0; i < printCoordinate.size(); i++)
//		{
//			if(!(printCoordinate[i].x == CONSrowX && printCoordinate[i].y == CONcolumnY && i != 0) )
//			{
//				cout << printCoordinate[i].x << " " << printCoordinate[i].y << endl;
//			}
//		}
//	}
//}
//int main()
//{
//	ifstream input;
//	string fileName;
//	OpenStudentFile(input, fileName);//Opens the file and updates ifstream input.
//	string line;
//	vector<vector<char>> matrix;
//	int counter = 0;
//	while(getline(input, line))//Gets the filestream line by line
//	{
//		istringstream iss(line);//Sends the filestream into lines.
//		char x;
//		matrix.push_back(vector<char>());
//		while(iss >> x)//Reads the line char by char
//		{
//			matrix[counter].push_back(x);//Adds the chars to the vector.
//		}
//		counter ++;
//	}
//	if(CheckMatrix(matrix, fileName))//If the matrix is valid
//	{
//		PrintMatrix(matrix);//Prints the matrix as output.
//		int rowX, rowY;
//		do
//		{
//			cout << "Please enter starting coordinates, first row X then column Y:";
//			if(cin >> rowX >> rowY)//Takes the input if its valid int
//			{
//				if(0 <= rowX && rowX <= matrix.size() - 1)
//				{
//					if(0 <= rowY && rowY <= matrix[0].size()-1)
//					{
//						vector<vector<char>> visitedCoordinates(matrix.size(), vector<char>(matrix[0].size()));
//						vector<Coordinate> printCoordinate;
//						if (matrix[rowX][rowY] == 'x')
//						{
//							bool end = false;
//							visitedCoordinates[rowX][rowY] = '1';
//							Coordinate xy; xy.x = rowX; xy.y = rowY;;
//							printCoordinate.push_back(xy);
//							CheckClosedArea(matrix, rowX, rowY, visitedCoordinates, printCoordinate, rowX, rowY, end);
//						}
//						else
//						{
//							cout << "This cell is not occupied!" << endl;
//						}
//					}
//					else
//					{
//						cout << "Invalid Coordinates" << endl;
//					}
//				}
//				else if( (rowX != -1 && rowY != -1))
//				{
//					cout << "Invalid Coordinates" << endl;
//				}
//			}
//			else//If the input is something other than int.
//			{
//				cin.clear();//Clears the error flags.
//				cin.seekg(0);
//				cout << "Invalid Coordinates" << endl;
//			}
//		}while (rowX != -1 && rowY != -1);
//		cout << "Terminating..." << endl;
//	}
//	return 0;
//}