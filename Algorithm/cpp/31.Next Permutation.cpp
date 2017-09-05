/*
 * 31. Next Permutation
 * Implement next permutation,which rearanges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible,it must rearrange it as lowest possible order(ie,sorted in ascending order).
 * The replacement must be in-place,do not allocate extra memory.
 * Here are some examples.Inputs are in the left-hand column and its corresponding outputs are in the righthand column.
 * 1,2,3 -> 1,3,2
 * 3,2,1 -> 1,2,3
 * 1,1,5 -> 1,5,1
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        if (nums.size() <= 1) return;

        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {
                int j = nums.size() - 1;
                while (nums[i - 1] >= nums[j])
                {
                    //pass
                    j--;
                }
                int tmp = nums[j];
                nums[j] = nums[i - 1];
                nums[i - 1] = tmp;               
                reverse(nums.begin()+i,nums.end());
                return;
            }

            //edge case:4 3 2 1
            if (i == 1)
            {
                reverse(nums.begin(),nums.end());
                return;
            }
        }
    }
};

int main()
{
    vector<int> v = { 1,5,1 };
    Solution s;
    s.nextPermutation(v);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
