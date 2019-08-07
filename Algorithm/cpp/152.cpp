/*
 * 152. Maximum Product Subarray
 * Given an integer array nums, find the continguous subarray within an array (containing at least one number)
 * which has the largest product.
 *
 * Example 1:
 *  Input: [2,3,-2,4]
 *  Output: 6
 *  Explanation: [2,3] has the largest product 6.
 *
 * Example 2:
 *  Input : [-2,0,-1]
 *  Output: 0
 *  Expanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using std::vector; using std::next; using std::prev; using std::advance;
#define CATCH_CONFIG_MAIN
#include "catch.h"  //catch2 v2.9.1

class Solution {
public:
    int maxProduct(vector<int>nums)
    {
        vector<int> f, g;
        f.push_back(nums[0]);
        g.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            f.push_back(max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]));
            g.push_back(min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]));
        }
        int m = f[0];
        for (int i = 1; i < f.size(); ++i)
            m = max(m, f[i]);
        return m;
    }

};

TEST_CASE("Find Maximum Product Subarray", "[maxProduct]")
{
    SECTION("as question")
    {
        std::vector<int> vec{ 2,3,-2,4 };
        Solution s;
        REQUIRE(s.maxProduct(vec) == 6);
    }

    SECTION("case more")
    {
        std::vector<int> vec{ -2,0,-1 };
        Solution s;
        REQUIRE(s.maxProduct(vec) == 0);
    }
}
