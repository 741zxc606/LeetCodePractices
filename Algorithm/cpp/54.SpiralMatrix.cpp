/*
 * 54. Spiral Matrix
 * Given a matrix of m * n elements(m rows,ncolumns),return all elements of the matrix in spiral order
 */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sparilOrder(vector<vector<int>>& matrix)
	{
		vector<int> result;
		int row = matrix.size();
		if (row == 0) return result;
		int col = matrix.size();
		if (col == 0) return result;

		//define the steps for 4 diretions
		int x[4] = {1,0,-1,0};
		int y[4] = {0,1,0,-1};

		int visitedRows = 0;
		int visitedCols = 0;

		//define diretions: 0 right,1 down,2 left,3 up
		int direction = 0;
		int startx = 0, starty = 0;
		int candidateNum = 0, moveStep = 0;
		while (true)
		{
			if (x[direction] == 0)//visit y aixs
				candidateNum = row - visitedRows;
			else//visit x aixs
				candidateNum = col - visitedCols;

			if (candidateNum <= 0)
				break;
			result.push_back(matrix[starty][startx]);
			moveStep++;
			if (candidateNum == moveStep)//change direction
			{
				visitedRows += x[direction] == 0 ? 0 : 1;
				visitedCols += x[direction] == 0 ? 0 : 1;
				direction = (direction + 1) % 4;
				moveStep = 0;
			}
			startx += x[direction];
			starty += y[direction];
		}
		return result;
	}
};

//void printArray(vector<int> v)
//{
//	cout << "[";
//	for (int i = 0; i < v.size(); i++)
//	{
//		printf(" %d", v[i]);
//	}
//	cout << "]" << endl;
//}

int main()
{
	Solution s;
	std::vector<std::vector<int>> matrix =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	vector<int> v = s.sparilOrder(matrix);
	//printArray(v);
	cout << "[";
	for (int i = 0; i < v.size(); i++)
	{
		printf(" %d", v[i]);
	}
	cout << "]" << endl;

	return 0;
}
