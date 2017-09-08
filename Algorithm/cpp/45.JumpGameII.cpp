/*
 * 45. Jump Game II
 * Given an array of non-negative integers,you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * For example:
 * Given array A = [2,3,1,1,4]
 * The minimum number of jumps to reach the last index is 2.(Jump 1 step from index 0 to 1,then 3 steps to the last index.)
 * Note:
 * You can assume that you can always reach the last index.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        int minstep = 0;
        int ldist = 0;
        int hdist = 0;
        if (n == 1) return 0;
        while (ldist <= hdist)
        {
            ++minstep;
            int lasthdist = hdist;
            for (int i = ldist; i <= lasthdist; ++i) 
            {
                int possibledist = i + nums[i];
                if (possibledist >= n - 1)
                    return minstep;
                if (possibledist > hdist)
                {
                    hdist = possibledist;
                }
            }
            ldist = lasthdist + 1;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int arr1[] = {3,2,1,0,4};
    int arr2[] = {2,3,1,1,4};

    vector<int> A1(begin(arr1), end(arr1));
    vector<int> A2(begin(arr2), end(arr2));

    std::cout << std::boolalpha << s.jump(A1) << std::endl;
    std::cout << std::boolalpha << s.jump(A2) << std::endl;

    return 0;
}
