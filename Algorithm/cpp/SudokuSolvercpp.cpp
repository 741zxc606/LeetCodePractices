/*
 * 37. Sudoku Solver
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * Empty cells are indicated by charater '.'.
 * You may assume that there will be only one unique solution.
 */

#include <vector>
using std::vector;
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution
{
	bool findEmptyCell(const vector<vector<char>>&board, size_t &row, size_t &col)
	{
		for (row = 0; row < board.size(); ++row)
			for (col = 0; col < board[row].size(); ++col)
				if (board[row][col] == '.') return true;
		return false;
	}
	bool isSafe(const vector<vector<char>> &board, size_t row, size_t col, char c)
	{
		for (size_t i = 0; i < 9; ++i)
		{
			if (board[row][i] == c) return false;
			if (board[i][col] == c) return false;
			if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == c) return false;
		}
		return true;
	}
public:
	bool solveSudoku(vector<vector<char>>&board)
	{
		size_t row = 0, col = 0;
		if (!findEmptyCell(board, row, col)) return true;
		for (char c : {'1', '2', '3', '4', '5', '6', '7', '8', '9'})
			if (isSafe(board, row, col, c))
			{
				board[row][col] = c;
				if (solveSudoku(board)) return true;
				board[row][col] = '.';
			}
		return false;
	}
};

int main()
{
	Solution s;
	vector<std::vector<char>> board =
	{
		{ '5','3','.','.','7','.','.','.','.' },
		{ '6','.','.','1','9','5','.','.','.' },
		{ '.','9','8','.','.','.','.','6','.' },
		{ '8','.','.','.','6','.','.','.','3' },
		{ '4','.','.','8','.','3','.','.','1' },
		{ '7','.','.','.','2','.','.','.','6' },
		{ '.','6','.','.','.','.','2','8','.' },
		{ '.','.','.','4','1','9','.','.','5' },
		{ '.','.','.','.','8','.','.','7','9' },
	};
	s.solveSudoku(board);

	for (const auto &v : board)
	{
		for (auto c : v)
			std::cout << c << " ";
		cout << std::endl;
	}
	return 0;
}