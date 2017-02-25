#ifndef PA1_H
#define PA1_H
class Square
{
	
	
	public:
	//function for printing the square
	void printSquare(vector<vector<int> > &matrix);
	//function for adding up the values of the rows
	void sumRows(vector<vector<int> > &matrix);
	//function for adding up the values of the columns
	void sumColumns(vector<vector<int> > &matrix);
	//function for adding up the values of the diagonals
	void sumDiagonals(vector<vector<int> > &matrix);
	//function for rotating the square 90 degrees
	void rotateSquare(vector<vector<int> > &matrix);
};

#endif