/*
 * 79.Word Search
 * Given a 2D board and a word,find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell,where "adjacent" cells are those horizontally or vertically
 * neighboring.The same letter cell may not be used more than once.
 * For example,
 * Given board = 
 * [
 *  ['A','B','C','E'],
 *  ['S','F','C','S'],
 *  ['A','D','E','E']
 * ]
 * word = "ABCCED",-> returns true,
 * word = "SEE",-> returns true,
 * word = "ABCB", -> returns false.
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        m = board.size();
        n = board[0].size();
        for (int x = 0; x < m; x++)        
            for (int y = 0; y < n; y++)
            {
                if (isFound(board, word.c_str(), x, y))
                    return true;
            }
        return false;
    }
private:
    int m;
    int n;
    bool isFound(vector<vector<char>>&board, const char* w, int x, int y)
    {
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '\0' || *w != board[x][y])
            return false;
        if (*(w + 1) == '\0')        
            return true;        
            char t = board[x][y];
            board[x][y] = '\0';
            if (isFound(board, w + 1, x - 1, y) || isFound(board, w + 1, x + 1, y) || isFound(board, w + 1, x, y - 1) || isFound(board, w + 1, x, y + 1))
                return true;
            board[x][y] = t;
        return false;
    }
};

vector<vector<char>> buildBoard(char b[][5], int r, int c)
{
    vector<vector<char>>board;
    for (int i = 0; i < r; i++)
    {
        vector<char> v(b[i], b[i] + c);
        cout << b[i] << endl;
        board.push_back(v);
    }
    cout << "---------" << endl;
    return board;
}

int main()
{
    Solution s;
    string str;
    char b[3][5] = { "ABCE", "SFCS", "ADEE" };
    vector< vector<char> > board = buildBoard(b, 3, 4);
    
    str = "SEE";
    cout << str << ":" << s.exist(board, str) << endl;

    str = "ABCCED";
    cout << str << ":" << s.exist(board, str) << endl;

    str = "ABCB";
    cout << str << ":" << s.exist(board, str) << endl;

    return 0;
}
