/*
 * 81.Search in Rotated Sorted Array II
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * Would this affect the run-time complexity?How and Why?
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e.,0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Write a function to determine if a given target is in the array.
 * The array may contain duplicates.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool search(vector<int>&nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int mid = 0;
        if (n <= 0) return false;//null
        while (low < high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[high])
            {
                if (nums[mid] > target && nums[low] <= target) high = mid;
                else low = mid + 1;
            }
            else if (nums[mid] < nums[high])
            {
                if (nums[mid] < target && nums[high] >= target) low = mid + 1;
                else high = mid;
            }
            else
            {
                high--;
            }
        }
        return nums[low] == target ? true : false;
    }
};

int main()
{
    Solution s;
    vector<int> nums{ 0,1,1,2,2,3,3 };
    cout << s.search(nums, 3) << endl;
    return 0;
}
