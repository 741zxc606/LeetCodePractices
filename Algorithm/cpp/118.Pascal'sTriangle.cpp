/*
 * 118.Pascal's Triangle
 * Given numRows,generate the first numRows of Pascal's triangle.
 * For example,given numRows = 5,
 * Return 
   [
         [1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]
   ]
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++)
        {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        return r;
    }
};

int main()
{
    Solution s;
    for (auto vec : s.generate(6))
    {
        for (auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}
