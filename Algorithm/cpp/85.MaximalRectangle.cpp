/*
 * 85.Maximal Rectangle
 * Given a 2D binary matrix filled with 0's and 1's,find the largest rectangle containing only 1's and return its area.
 * For example,given the following matrix:
 *  1 0 1 0 0 
 *  1 0 1 1 1
 *  1 1 1 1 1 
 *  1 0 0 1 0
 * Return 6.
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>&heights)
    {
        int max_area = 0, i = 0, size = heights.size();
        for (stack<int>stk; i < size || !stk.empty();)
            if (stk.empty() || (i != size&&heights[stk.top()] <= heights[i])) stk.push(i++);
            else
            {
                int tp = stk.top(); stk.pop();
                max_area = max(max_area, heights[tp] * (stk.empty() ? i : i - stk.top() - 1));
            }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>&matrix)
    {
        if (matrix.empty()) return 0;
        int max_area = 0;
        vector<int> heights(matrix[0].size(), 0);
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix[0].size(); ++j)
                if (matrix[i][j] == '0') heights[j] = 0;
                else ++heights[j];
                max_area = max(max_area, largestRectangleArea(heights));
        }
        return max_area;        
    }
};

int main()
{
    std::vector<std::vector<char>> matrix = { {'1','0','1','0','0'},
                                              {'1','0','1','1','1'},
                                              {'1','1','1','1','1'},
                                              {'1','0','0','1','0'}};

    Solution s;
    cout << s.maximalRectangle(matrix) << endl;
    return 0;
}
