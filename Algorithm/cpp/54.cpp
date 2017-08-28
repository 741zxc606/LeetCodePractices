/*
* 54. Spiral Matrix
* Given a matrix of m * n elements(m rows,ncolumns),return all elements of the matrix in spiral order
*/

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		const int m = matrix.size();
		vector<int> res;
		if (m == 0)
		{
			return res;
		}

		const int n = matrix.front().size();
		enum Action { RIGHT, DOWN, LEFT, UP };
		Action action = RIGHT;
		for (int i = 0, j = 0, begini = 0, beginj = 0, endi = m,
			endj = n, cnt = 0, total = m * n; cnt < total; ++cnt)
		{
			res.emplace_back(matrix[i][j]);

			switch (action)
			{
			case RIGHT:
				if (j + 1 < endj)
				{
					++j;
				}
				else
				{
					action = DOWN, ++begini, ++i;
				}
				break;

			case DOWN:
				if (i + 1 < endi)
				{
					++i;

				}
				else
				{
					action = LEFT, --endj, --j;
				}
				break;

			case LEFT:
				if (j - 1 >= beginj)
				{
					--j;
				}
				else
				{
					action = UP, --endi, --i;
				}
				break;

			case UP:
				if (i - 1 >= begini)
				{
					--i;
				}
				else
				{
					action = RIGHT, ++beginj, ++j;
				}
				break;

			default:
				break;
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	std::vector<std::vector<int>> matrix =
	{
		{ 1,2,3 },
		{ 4,5,6 },
		{ 7,8,9 }
	};

	vector<int> v = s.spiralOrder(matrix);
	
	cout << "[";
	for (int i = 0; i < v.size(); i++)
	{
		printf(" %d", v[i]);
	}
	cout << "]" << endl;

	return 0;
}
