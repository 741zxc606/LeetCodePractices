/*
 * 41. First Missing Positive
 * Given an unsorted integer array,find the first missing positive integer.
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * Your algorithm should run in O(n) time and uses constant space.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            while (nums[i] > 0 && nums[i] <= n&&nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1) return i + 1;
        return n + 1;
    }
};

int main()
{
    Solution s;
    int arr1[] = {1,2,0};
    int arr2[] = {3,4,-1,1};

    vector<int> A1(begin(arr1),end(arr1));
    vector<int> A2(begin(arr2),end(arr2));

    cout << s.firstMissingPositive(A1) << endl;
    cout << s.firstMissingPositive(A2) << endl;
}
