/*
 * 53.Maximum Subarray
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * For example,given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the configuous subarray [4,-1,2,1] has the largest sum = 6.
 *
 * More practice:
 * If you have figured out the O(n) solution,try coding another solution using the divide and conquer approach,
 * which is more subtle.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int sum = 0, minSum = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxSum = max(maxSum, sum - minSum);
            minSum = min(minSum, sum);
        }
        return maxSum;
    }
};

int main()
{
    vector<int> A{ -2,1,-3,4,-1,2,1,-5,4 };
    Solution s;
    cout << s.maxSubArray(A) << endl;
    return 0;
}
