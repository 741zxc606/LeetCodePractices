/*
 * 154. Find Minimum in Rotated Sorted Array II
 * Suppose an array sorted in ascending order is rotated at some privot
 * unknown to you beforehead.
 * (i.e. [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2])
 * Find the minimum element.
 * The array may contain duplictes.
 * 
 * Example 1:
 *  Input: [1,3,5]
 *  Output: 1
 *
 * Example 2:
 *  Input: [2,2,2,0,1]
 *  Output: 0
 */

#include <stdio.h>
#include <math.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.h"  //catch2 v2.9.1
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        return findMin(nums, 0, nums.size() - 1);
    }

    int findMin(const vector<int>& nums, int l, int r)
    {
        // One or two elements, solve it directly
        if (l + 1 >= r) return
            min(nums[l], nums[r]);

        // Sorted
        if (nums[l] < nums[r])
            return nums[l];

        int m = l + (r - l) / 2;

        // Recursively find the solution
        return min(findMin(nums, l, m - 1),
            findMin(nums, m, r));
    }
};

TEST_CASE("Find Minimum in Rotated Sorted Array II", "[findMin]")
{
    SECTION("Example 1")
    {
        std::vector<int> vec1{ 1,3,5 };
        Solution s;
        REQUIRE(s.findMin(vec1) == 1);
    }

    SECTION("Example 2")
    {
        std::vector<int> vec2{ 2,2,2,0,1 };
        Solution s;
        REQUIRE(s.findMin(vec2) == 0);
    }
}
