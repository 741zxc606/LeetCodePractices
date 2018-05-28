/*
 * 189.Rotate Array
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 * Example 1: 
 *      Input: [1,2,3,4,5,6,7] and k = 3
 *      Output: [5,6,7,1,2,3,4]
 *      Explanation: 
 *      rotate 1 steps to the right: [7,1,2,3,4,5,6]
 *      rotate 2 steps to the right: [6,7,1,2,3,4,5]
 *      rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * Example 2:
 *      Input: [-1,-100,3,99] and k = 2
 *      Output: [3,99,-1,-100]
 *      Explanation: 
 *      rotate 1 steps to the right: [99,-1,-100,3]
 *      rotate 2 steps to the right: [3,99,-1,-100]
 * Note: 
 *      1. Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 *      2. Could you do it in-place with O(1) extra space?
 */

#include <iostream>
#include <vector>
#include <ostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        if (!nums.empty())
        {
            k %= nums.size();
            reverse(nums.begin(), nums.begin() + nums.size() - k);
            reverse(nums.begin() + nums.size() - k, nums.end());
            reverse(nums.begin(), nums.end());
        }
    }
};

void printVector(vector<int>v)
{
    cout << "[";
    int i = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << (i == v.size() - 1 ? "]" : ",");
    }
    cout << endl;
}

int main()
{
    Solution a;

    int vec1[] = {1,2,3,4,5,6,7};
    int vec2[] = { -1, -100, 3, 99 };
    int k1 = 3;
    int k2 = 2;

    vector<int> v1(vec1, vec1 + 7);
    vector<int> v2(vec2, vec2 + 4);

    a.rotate(v1, k1);
    a.rotate(v2, k2);

    printVector(v1);
    printVector(v2);

    return 0;
}
