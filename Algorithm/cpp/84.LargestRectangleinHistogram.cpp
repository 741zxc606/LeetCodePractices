/*
 * 84.Largest Rectangle in Histogram
 * Given n non-negative integers representing the histogram's bar where the width of each bar is 1,
 * find the area of largest rectangle in the histogram.
 *
 *                    6
 *                  +---+
 *               5  |   |
 *              +---+   |
 *              |   |   |
 *              |   |   |
 *              |   |   |     3
 *              |   |   |   +---+
 *        2     |   |   | 2 |   |
 *      +---+   |   |   +---+   |
 *      |   | 1 |   |   |   |   |
 *      |   +---+   |   |   |   |
 *      |   |   |   |   |   |   |
 *      +---+---+---+---+---+---+
 *
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *
 *
 *                    6
 *                  +---+
 *               5  |   |
 *              +-------|
 *              |-------|
 *              |-------|
 *              |-------|     3
 *              |-------|   +---+
 *        2     |-------| 2 |   |
 *      +---+   |-------|---+   |
 *      |   | 1 |-------|   |   |
 *      |   +---|-------|   |   |
 *      |   |   |-------|   |   |
 *      +---+---+---+---+---+---+
 *
 * The largest rectangle is shown in the shaded area,which has area =10 unit.
 *
 * For examplr,
 * Given heights=[2,1,5,6,2,3],
 * return 10.
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int max_area = 0, i = 0, size = heights.size();
        for (stack<int> stk; i < size || !stk.empty();)
            if (stk.empty() || (i != size&&heights[stk.top()] <= heights[i])) stk.push(i++);
            else
            {
                int tmp = stk.top(); stk.pop();
                max_area = max(max_area,heights[tmp]*(stk.empty()?i:i-stk.top()-1));
            }
        return max_area;
    }
};

int main()
{
    std::vector<int> heights{ 6,2,5,4,5,1,6 };
    Solution s;
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}
