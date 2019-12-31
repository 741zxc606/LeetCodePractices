/*
 * 215. Kth Largest Element in an Array
 * Find the kth largest elemenet in an unsorted array. Note that it is the kth largest
 * element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *   Input: [3,2,1,5,6,4] and k = 2
 *   Output: 5
 *
 * Example 2:
 *   Input: [3,2,3,1,2,4,5,5,6] and k = 4
 *   Output: 4
 *
 * Note:
 * You may assume k is always valid, 1<= k <= array's length.
 */

#include <stdio.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int size = nums.size();
        int l = 0, r = size - 1;

        k = size - k;
        while (l < r)
        {
            int key = nums[l + r >> 1];
            int i = l - 1, j = r + 1;

            while (i < j)
            {
                do
                {
                    i++;
                } while (nums[i] < key);
                do
                {
                    j--;
                } while (nums[j] > key);

                if (i < j)
                    swap(nums[i], nums[j]);
            }
            if (j >= k)
                r = j;
            else
                l = j + 1;
        }
        return nums[k];
    }
};

TEST_CASE("Kth Largest Element in an Array", "nums[k]")
{
    SECTION("Example 1")
    {
        std::vector<int> vec1{3,2,1,5,6,4};
        int k1 = 2;
        Solution s;
        REQUIRE(s.findKthLargest(vec1, k1) == 5);
    }

    SECTION("Example 2")
    {
        std::vector<int> vec2{ 3,2,3,1,2,4,5,5,6 };
        int k2 = 4;
        Solution s;
        REQUIRE(s.findKthLargest(vec2, k2) == 4);
    }
}


