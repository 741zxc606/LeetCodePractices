/*
 * 167. Two Sum II - Input array is sorted
 * Given an array of integers that is already sorted in ascending order, find two numbers such that
 * they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 should be less than index2.
 *
 * Note:
 *  * Your returned answers (both index1 and index2) are not zero-based.
 *  * You may assume that each input would have exactly one solution and you may not
 *    use the same element twice.
 * 
 * Example:
 *  Input: numbers = [2,7,11,15], target = 9;
 *  Output: [1,2]
 *  Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 */

#include <stdio.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> numbers, int target)
    {
        vector<int> result;
        int low = 0, high = numbers.size() - 1;
        while (low < high)
        {
            if (numbers[low] + numbers[high] == target)
            {
                result.push_back(low + 1);
                result.push_back(high + 1);
                return result;
            }
            else
            {
                numbers[low] + numbers[high] > target ? high-- : low++;
            }
        }
        return result;
    }
};

TEST_CASE("Two Sum II - Input array is sorted", "[twoSum]")
{
    SECTION("Example 1")
    {
        std::vector<int> vec1{ 2,7,11,15 };
        int target1 = 9;
        Solution s;
        REQUIRE(s.twoSum(vec1, target1) == std::vector <int> {1, 2});
    }
}
