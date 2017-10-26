/*
 * 80.Remove Duplicates from Sorted Array II
 * Follow up for "Remove Diplicates".
 * What if duplicates are allowed at most twice?
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * Your function should return length = 5,with the first five elements of nums being 1,1,2,2,and 3.
 * It doesn't matter what you leave beyond the new length.
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i = 0;
        for (int n : nums)
            if (i<2 || n>nums[i - 2])
                nums[i++] = n;
        return i;
    }
};

void printVector(vector<int>& v)
{    
    printf("{");
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d,", v[i]);        
    }
    printf("}");
    cout << endl;
}

int main()
{
    Solution s;
    vector<int>nums{ 1,1,1,2,2,3 };
    cout << s.removeDuplicates(nums) << endl;
    printVector(nums);
    return 0;
}
