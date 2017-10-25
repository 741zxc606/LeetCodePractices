/*
 * 75.Sort Colors
 * Given an array with n objects colored red,white or blue,sort them so that objects of the same color are adjacent,with the colors int the
 * order red,white and blue.
 * Here,we will use the integers 0,1,and 2 to represent the color red,white,and blue respectively.
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First,iterate the array counting number of 0's,1's,and 2's,then overwrite array with total number of 0's,then 1's and followed by 2's.
 * Could you please come up with an one-pass algorithm using only constant space?
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void sortColor(vector<int>& nums)
    {
        int n = nums.size();
        int second = n - 1, zero = 0;
        for (int i = 0; i <= second; i++)
        {
            while (nums[i] == 2 && i < second) swap(nums[i], nums[second--]);
            while (nums[i] == 0 && i > zero) swap(nums[i], nums[zero++]);
        }
    }
};

int main()
{
    vector<int> vec { 1,2,0,1,0,0,2,1 };
    Solution s;
    s.sortColor(vec);
    for (auto i : vec)
        std::cout << i << std::endl;
    return 0;
}
