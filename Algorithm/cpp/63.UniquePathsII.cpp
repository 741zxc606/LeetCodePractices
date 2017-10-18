/*
 * 63.Unique Paths II
 * Follow up for "Unique Paths".
 * Now consider if some obstacles are added to the grids.How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * For example,
 * There is one obstacle in the middle of a 3X3 grid as illutrated below.
 *  [
 *      [0,0,0],
 *      [0,1,0],
 *      [0,0,0]
 *  ]
 * The total number of unique paths is 2.
 * Note:m and n will be at most 100.
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using std::vector;
using std::prev;
using namespace std;

class Solution {
public:
    int uniquePathWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>>v = obstacleGrid;
        unsigned int max = 0;
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < obstacleGrid[i].size(); j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    max = v[i][j] = 0;
                }
                else
                {
                    if (i > 0 && j > 0)
                    {
                        max = v[i][j] = v[i - 1][j] + v[i][j - 1];
                    }
                    else if (i > 0)
                    {
                        max = v[i][j] = v[i - 1][j];
                    }
                    else if (j > 0)
                    {
                        max = v[i][j] = v[i][j - 1];
                    }
                    else
                    {
                        max = v[i][j] = 1;
                    }
                }
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> vec1{ {0,0,0},{0,1,0},{0,0,0,} };
    std::cout << s.uniquePathWithObstacles(vec1) << std::endl;

    std::vector<std::vector<int>> vec2{ {1,1} };
    std::cout << s.uniquePathWithObstacles(vec2) << std::endl;

    return 0;
}
