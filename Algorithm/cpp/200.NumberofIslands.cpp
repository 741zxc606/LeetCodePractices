/*
 * 200.Number of Islands
 * Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.An island is surrounded by water and is formed by
 * connectiong adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 * Example 1: 
 *      Input: 
 *      11110
 *      11010
 *      11000
 *      00000
 *      Output: 1
 * Example 2:
 *      Input: 
 *      11000
 *      11000
 *      00100
 *      00011
 *      Output: 3
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void mark(vector<vector<char>>&grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '1')
        {
            return;
        }
        
        grid[r][c] = 'M';

        //left
        mark(grid, r, c + 1);
        //right
        mark(grid, r, c - 1);
        //up
        mark(grid, r - 1, c);
        //down
        mark(grid, r + 1, c);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int result = 0;
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[r].size(); c++)
            {
                if (grid[r][c] == '1')
                {
                    result++;
                    mark(grid, r, c);
                }
            }
        }
        return result;
    }
};

void initGrid(string g[], int len, vector<vector<char>>&grid)
{
    for (int i = 0; i < len; i++)
    {
        grid.push_back(vector<char>(g[i].begin(), g[i].end()));
    }
}

int main()
{
    vector<vector<char>> grid;
    Solution s;

    grid.push_back(vector<char>(1, '0'));
    cout << s.numIslands(grid) << endl;

    grid.clear();

    grid.push_back(vector<char>(1, '1'));
    cout << s.numIslands(grid) << endl;

    grid.clear();

    string g1[] = {"11110",
                   "11010",
                   "11000",
                   "00000"};

    initGrid(g1, 4, grid);
    cout << s.numIslands(grid) << endl;

    grid.clear();

    string g2[] = { "11000",
                    "11000",
                    "00100",
                    "00011" };

    initGrid(g2, 4, grid);
    cout << s.numIslands(grid) << endl;

    return 0;
}
