/*
 * 36. Valid Sudoku
 * Determine if a Sudoku is valid, according to : http://sudoku.com.au/TheRules.aspx
 * The Sudoku board could be partially filled,where empty cells are filled with the character '.' .
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        std::unordered_map<size_t, std::unordered_set<char>> row_map, col_map, cel_map;
        for (size_t i = 0; i<board.size(); ++i)
            for (size_t j = 0; j<board[0].size(); ++j)
            {
                if (board[i][j] == '.') continue;
                if (!row_map[i].insert(board[i][j]).second) return false;
                if (!col_map[j].insert(board[i][j]).second) return false;
                if (!cel_map[i / 3 * 10 + j / 3].insert(board[i][j]).second) return false;
            }
        return true;
    }
};

int main()
{
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

    Solution s;
    std::cout << std::boolalpha << s.isValidSudoku(board) << std::endl;
}
