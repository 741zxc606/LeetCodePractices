/*
* 42. Trapping Rain Water
*  Given n non-negative integes representing an elevation map where the width of each bar is 1,
* compute how much water it is able to trap after raining.
* For example,
* Given [0,1,0,2,1,0,1,3,2,1,2,1],return 6.
* Given n non-negative integers representing an elevation map where the width of each bar is 1,
* compute how much water it is able to trap after raining.
*
* For example,
* Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*
*     ^
*     |
*   3 |                       +--+
*     |                       |  |
*   2 |          +--+xxxxxxxxx|  +--+xx+--+
*     |          |  |xxxxxxxxx|  |  |xx|  |
*   1 |   +--+xxx|  +--+xxx+--+  |  +--+  +--+
*     |   |  |xxx|  |  |xxx|  |  |  |  |  |  |
*   0 +---+--+---+--+--+---+--+--+--+--+--+--+----->
*       0  1   0  2  1   0  1  3  2  1  2  1
*
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
* 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*
*/

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        int result = 0;
        int n = height.size();
        //find the highest value/position
        int maxHigh = 0;
        int maxIdx = 0;
        for (int i = 0; i < n; i++)
        {
            if (height[i] > maxHigh)
            {
                maxHigh = height[i];
                maxIdx = i;
            }
        }

        //from the left to the highest position
        int prevHigh = 0;
        for (int i = 0; i < maxIdx; i++)
        {
            if (height[i] > prevHigh)
            {
                prevHigh = height[i];
            }
            result += (prevHigh - height[i]);
        }

        //from the right to the highest position
        prevHigh = 0;
        for (int i = n - 1; i > maxIdx; i--)
        {
            if (height[i] > prevHigh)
            {
                prevHigh = height[i];
            }
            result += (prevHigh - height[i]);
        }

        return result;
    }
};

int main()
{
    Solution s;
    int arr1[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    vector<int> A1(begin(arr1), end(arr1));
    cout << s.trap(A1) << endl;
}
