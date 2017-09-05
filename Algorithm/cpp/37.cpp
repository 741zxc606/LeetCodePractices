/*
 * 37. Sudoku Solver
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * Empty cells are indicated by charater '.'.
 * You may assume that there will be only one unique solution.
 */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <vector>
using namespace std;

const int SudokuSize = 9;
bool row_mask[SudokuSize][SudokuSize];
bool col_mask[SudokuSize][SudokuSize];
bool area_mask[SudokuSize][SudokuSize];

class Solution{
public:
	bool initSudokuMask(vector<vector<char>>&board)
	{
		//reset the memory
		memset(row_mask, false, sizeof(row_mask));
		memset(col_mask, false, sizeof(col_mask));
		memset(area_mask, false, sizeof(area_mask));

		//check each row and col
		for (int r = 0; r < board.size(); r++)
		{
			for (int c = 0; c < board[r].size(); c++)
			{
				if (!isdigit(board[r][c]))
				{
					continue;
				}
				int idx = board[r][c] - '0' - 1;

				//check the rows/cols/areas
				int area = (r / 3) * 3 + (c / 3);
				if (row_mask[r][idx] || col_mask[c][idx] || area_mask[area][idx])
				{
					return false;
				}
				row_mask[r][idx] = col_mask[c][idx] = area_mask[area][idx] = true;
			}
		}
		return true;
	}

	bool recursiveSudoku(vector<vector<char>>&board, int row, int col)
	{
		if (row >= SudokuSize)
		{
			return true;
		}
		if (col >= SudokuSize)
		{
			return recursiveSudoku(board, row + 1, 0);
		}
		if (board[row][col] != '.')
		{
			return recursiveSudoku(board, row, col + 1);
		}

		//pick a number for empty cell
		int area;
		for (int i = 0; i < SudokuSize; i++)
		{
			area = (row / 3) * 3 + (col / 3);
			if (row_mask[row][i] || col_mask[col][i] || area_mask[area][i])
			{
				continue;
			}
			//set the number and sovle it recurively
			board[row][col] = i + '1';
			row_mask[row][i] = col_mask[col][i] = area_mask[area][i] = true;
			if (recursiveSudoku(board, row, col + 1) == true)
			{
				return true;
			}
			//backtrace
			board[row][col] = '.';
			row_mask[row][i] = col_mask[col][i] = area_mask[area][i] = false;
		}
		return false;
	}

	void solveSudoku(vector<vector<char>>&board)
	{
		if (initSudokuMask(board) == false)
		{
			return;
		}
		recursiveSudoku(board, 0, 0);
	}
};

int main()
{
	vector<std::vector<char>> board =
	{
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'},
	};
	
	Solution s;
	s.solveSudoku(board);

	for (const auto &v : board)
	{
		for (auto c : v)
			std::cout << c << " ";
		cout << std::endl;
	}
	return 0;
}
