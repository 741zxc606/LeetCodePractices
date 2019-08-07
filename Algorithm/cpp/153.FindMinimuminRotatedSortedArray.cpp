/*
 * 153. Find Minimum in Rotated Sorted Array
 * Supposed an array sorted in ascending order is rotated at some privot
 * unknown to you beforehand.
 * (i.e. [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * Find the minimum element.
 * You may assume no duplicate exisits in the array.
 * 
 * Example 1:
 *  Input: [3,4,5,1,2]
 *  Output: 1
 *
 * Example 2:
 *  Input: [4,5,6,7,0,1,2]
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
        auto beg = nums.begin();
        for (auto end = std::prev(nums.end()); beg < end; )
        {
            if (*beg < *end) break;
            auto mid = (end - beg) >> 1;
            *beg <= *next(beg, mid) ? advance(beg, mid + 1) : advance(end, -mid );
        }
        return *beg;
    }
};

TEST_CASE("Find Minimum in Rotated Sorted Array", "[findMin]")
{
    SECTION("Examople 1")
    {
        std::vector<int> vec1{ 3,4,5,1,2 };
        Solution s;
        REQUIRE(s.findMin(vec1) == 1);
    }

    SECTION("Example 2")
    {
        std::vector<int> vec2{ 4,5,6,7,0,1,2 };
        Solution s;
        REQUIRE(s.findMin(vec2) == 0);
    }
}
