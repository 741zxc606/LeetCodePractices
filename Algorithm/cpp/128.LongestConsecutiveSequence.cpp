/*
 * 128.Longest Consecutive Sequence
 * Given an unsorted array of integers,find the length of the longest consecutice elements sequence.
 * For example,
 * Given [100,4,200,1,3,2],
 * The longest consecutive elemeents sequence is [1,2,3,4,].Return its length :4.
 * Your algorithm should run in O(n) complexity.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutice(vector<int>&nums)
    {
        unordered_map<int, int>map;
        int max{ 0 };
        for(auto i:nums)
            if (!map[i])
            {
                map[i] = map[i + 1] + map[i - 1] + 1;
                map[i - map[i - 1]] = map[i + map[i + 1]] = map[i];
                max = std::max(max, map[i]);
            }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> vec{ 100,4,200,1,3,2 };
    cout << s.longestConsecutice(vec) << endl;
    return 0;
}
