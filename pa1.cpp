#include <vector>
#include <iostream>
using namespace std;
#include "pa1.h"
//prints out the given matrix based on a function in the "Square" class
//uses vectors in order to pass the matrix
void Square::printSquare(vector<vector<int> > &matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			//prints out with two spaces for one digit
			if (matrix[i][j] <= 9)
			{
				cout << "  " << matrix[i][j] << " " ;
			}
			//prints out with 1 space for two digits
			if (matrix[i][j] >= 10 && matrix[i][j] <= 99)
			{
				cout << " " << matrix[i][j] << " " ;
			}
			//prints out with no spaces for three digits
			if (matrix[i][j] >= 100 && matrix[i][j] <= 999)
			{
				cout << matrix[i][j] << " " ;
			}
		}
		cout << "\n";
	}
}
//adds up the sum of each row into a matrix the size of N.
//each row gets its own value in the repective index of the matrix
//It does this by adding each value within the given row until it reaches the end.
//It then sets that value to the respective index of sumRows[].
void Square::sumRows(vector<vector<int> > &matrix)
{
	int N = matrix.size();
	int sumRows[N];
	int sumR;
	std::cout << "Checking the sums of every row: ";
	for (int i = 0; i < N; i++)
	{
		sumR = 0;
		for (int j = 0; j < N; j++)
			sumR += matrix[i][j];
		sumRows[i] = sumR;
	}
	for (int i = 0; i < N; i++)
	{
		std::cout << sumRows[i] << " ";
	}
	std::cout << "\n";
}
//adds up the sum of each column into the matrix the size of N.
//just as the sum of the rows, each column gets its own value.
//It does this the same way as with the rows but with column values instead.
void Square::sumColumns(vector<vector<int> > &matrix)
{
	int N = matrix.size();
	int sumColumns[N];
	int sumC;
	std::cout <<"Checking the sums of every column: ";
	for (int i = 0; i < N; i++)
	{
		sumC = 0;
		for (int j = 0; j < N; j++)
			sumC += matrix[j][i];
		sumColumns[i] = sumC;
	}
	for (int i = 0; i < N; i++)
	{
		std::cout << sumColumns[i] << " ";
	}
	std::cout << "\n";
}
//function for adding up the sumd of the diagonals
//This is different than adding rows and columns for many reasons.
//There are only two diagonals in every case that would be added up.
//therefore an array with a size of two is created to place the values in.
//for the first diagonal it just adds up the values in the matrix[i][i] up to N.
//the second one starts from the bottom left and moves up to the top right.
void Square::sumDiagonals(vector<vector<int> > &matrix)
{
	int N = matrix.size();
	int sumDiagonals[2];
	int sumD;
	std::cout << "Checking the sums of every diagonal: ";
	sumD = 0;
	for (int i = 0; i <N; i++)
	{
		sumD += matrix[i][i];
	}
	sumDiagonals[0] = sumD;
	sumD = 0;
	for (int i = N-1, j = 0; j < N; i--, j++)
		sumD += matrix[i][j];
	sumDiagonals[1] = sumD;
	for (int i = 0; i < 2; i++)
		std::cout << sumDiagonals[i] << " ";
	std::cout << "\n";
}
//function to rotate the magic square by 90 degrees
void Square::rotateSquare(vector<vector<int> > &matrix)
{
	//gets the value of N from the size of the vector that is passed
	int N =matrix.size();
	//starts from first column
	//does this cycle for N/2 rather than N because all cells are coveren in N/2.
    for (int i = 0; i < N / 2; i++)
    {
        // focuss on changing values in a block of 4
		//for each value that is changed in the matrix.
        for (int j = i; j < N-i-1; j++)
        {
            //stores the first cell as a temp so it can be used
			//after being replaced
            int temp = matrix[i][j];
 
            //moves values from the right side of the matrix
			//places them at the top
            matrix[i][j] = matrix[j][N-1-i];
 
            //moves values from the bottom of the matrix
			//places the values to the right side of the matrix
            matrix[j][N-1-i] = matrix[N-1-i][N-1-j];
 
            //moves values from the left of the matrix
			//places the values to the bottom of the matrix.
            matrix[N-1-i][N-1-j] = matrix[N-1-j][i];
 
            //places the cells that were defined as temp to the left side of the matrix
            matrix[N-1-j][i] = temp;
        }
    }
}


int main()
{
	//askd for user input on size of the magic square
	std::cout << "Enter the size of the magic square: \n";
	//creates a variable that will be given the value of user input
	int N;
	bool validInput = false;
	//creates a while loop that checks the user input
	//makes sure that the input is an odd number between 3 and 15
	//if it is anything else, its asks for the user to try again
	//continues until valid input is accepted
	while (!validInput)
	{
		//takes user input
		std::cin >> N;
		//makes sure the input is a number between 2 and 16 exclusive
		if (N > 2 && N < 16)
		{
			//makes sure the input is odd
			if (N % 2 == 1)
				validInput = true;
			//fails otherwise
			else
				std::cout << "Invalid input. \n Please make sure the input is an odd number between 3 and 15. \n";
		}
		else
		{
			std::cin.clear();
			std::cin.ignore (1000, '\n');
			std::cout << "Invalid input. \n Please make sure the input is an odd number between 3 and 15. \n";
		}
	}
	//creates a matrix of N by N
int block[N][N];
//sets all values of the matrix to 0 after initialization
for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++)
		block[i][j] = 0;
}
int newRow, newColumn;
	int i = 0;
	int j = N/2;
	//creates the magic square
	//starts off from the middle of the first row
	//that values starts as 1 and the value goes up to N*N
	//the next value is assigned up one and to the right one
	//if the value in that location is anything other than one, the value goes below the previous one
	//when i < 0, it becomes N-1
	//when j = N, it becomes 0
	//this goes on until all cells are filled
	for (int value = 1; value <= N*N; value++)
	{
		block[i][j] = value;
		newRow = (i - 1);
		newColumn = (j + 1);
		if (newRow == -1)
		{
			newRow = N-1;
		}
		if (newColumn == N)
		{
			newColumn = 0;
		}
		if (block[newRow][newColumn] != 0)
		{
			newRow = i + 1;
			newColumn = j;
		}
		i = newRow;
		j = newColumn;
	}
	//creates an object of Square called magicSquare
	Square magicSquare;
	//creates a multidimentional vector of size N
	vector<vector<int> > vec(N, std::vector<int>(N));
	
	//sets all values from the matrix block into the vector vec in the same position
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vec[i][j] = block[i][j];
		}
	}
	//prints out the respective magic squares
	//also prints the sum of rows, columns, and diagonals respectively
	//then finally rotates it
	std::cout << "Magic Square #1 is: \n \n";
	magicSquare.printSquare(vec);
	std::cout << "\n";
	magicSquare.sumRows(vec);
	magicSquare.sumColumns(vec);
	magicSquare.sumDiagonals(vec);
	magicSquare.rotateSquare(vec);
	std::cout << "Magic Square #2 is: \n \n";
	magicSquare.printSquare(vec);
	std::cout << "\n";
	magicSquare.sumRows(vec);
	magicSquare.sumColumns(vec);
	magicSquare.sumDiagonals(vec);
	magicSquare.rotateSquare(vec);
	std::cout << "Magic Square #3 is: \n \n";
	magicSquare.printSquare(vec);
	std::cout << "\n";
	magicSquare.sumRows(vec);
	magicSquare.sumColumns(vec);
	magicSquare.sumDiagonals(vec);
	magicSquare.rotateSquare(vec);
	std::cout << "Magic Square #4 is: \n \n";
	magicSquare.printSquare(vec);
	std::cout << "\n";
	magicSquare.sumRows(vec);
	magicSquare.sumColumns(vec);
	magicSquare.sumDiagonals(vec);
	
}


