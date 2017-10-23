/*
 * 73.Set Matrix Zeroes
 * Given a m x n matrix,if an element is 0,set its entire row and column to 0.Do it in place.
 * Follow up:
 * Did you see use extra space?
 * A straight forward solutin using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m+n) space,but still not the best solution.
 * Could you devise a constant space solution?
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> vec{ {6,8,3,2},{0,4,2,2},{6,3,1,9},{1,5,8,0} };
    s.setZeroes(vec);
    for (const auto &v : vec)
    {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}
