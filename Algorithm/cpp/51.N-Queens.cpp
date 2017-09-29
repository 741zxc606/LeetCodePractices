/*
 * 51.N-Queens
 * The n-queens puzzle is the problem of placing n queens on an n*n chessboard such that no two queens attack each other.
 * Given an integer n,return all distinct solutions to the n-queens pizzle.
 * Each solution contains a distinct board configureation of the n-queens' palcement,where 'Q' and '.' both indicate a
 * queen and an empty space respectively.
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *  [
 *    [".Q..",   //Solution 1
 *     "...Q",
 *     "Q...",
 *     "..Q."],
 *
 *    ["..Q.",   //Solution 2
 *     "Q...",
 *     "...Q",
 *     ".Q.."]
 *  ]
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n)
    {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        /*
        flag[0] to flag[n - 1] to indicate if the column had a queen before.
        flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
        flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
        */
        std::vector<int> flag(5 * n - 2, 1);
        solveNQueens(res, nQueens, flag, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag, int row, int &n)
    {
        if (row == n)
        {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row])
            {
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag, row + 1, n);
                nQueens[row][col] = '.';
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
            }
    }
};

void printMatrix(vector<vector<string>>&matrix)
{
    for (int i = 0; i > matrix.size(); i++)
    {
        cout << "-----------" << endl;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << endl;
        }
    }
}

int main()
{    
    Solution s;

    for (const auto &v : s.solveNQueens(8))
    {
        for (const auto &s : v)
            std::cout << s << std::endl;
        std::cout << std::endl;
    }
}
