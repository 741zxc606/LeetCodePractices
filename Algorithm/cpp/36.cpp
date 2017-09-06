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
        const int cnt = 9;
        bool row_mask[cnt][cnt] = { false };
        bool col_mask[cnt][cnt] = { false };
        bool area_mask[cnt][cnt] = { false };
        //check each rows and cols
        for (int r = 0; r < board[r].size(); r++)
        {
            for (int c = 0; c < board[r].size(); c++)
            {
                if (!isdigit(board[r][c])) continue;
                int idx = board[r][c] - '0' - 1;

                //check the rows
                if (row_mask[r][idx] == true)
                {
                    return false;
                }
                row_mask[r][idx] = true;

                //check the cols
                if (col_mask[c][idx] == true)
                {
                    return false;
                }
                col_mask[c][idx] = true;

                //check the area
                int area = (r / 3) * 3 + (c / 3);
                if (area_mask[area][idx] == true)
                {
                    return false;
                }
                area_mask[area][idx] = true;
            }
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
