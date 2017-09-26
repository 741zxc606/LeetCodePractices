/*
 * 90.SubsetsII
 * Given a collection of integers that might contain duplicates,nums,return all possible subsets.
 * Note:The solution set must not contain duplicate subsets.
 * For example,
 * if nums=[1,2,2],a solution is:
 * [
 *  [2],
 *  [1],
 *  [1,2,2],
 *  [2,2],
 *  [1,2],
 *  []
 * ]
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret{ {} };
        for (size_t i = 0, b = 0, e = 0; i < nums.size(); ++i)
            for (b = (i&&nums[i] == nums[i - 1] ? e : 0), e = ret.size(); b < e; ++b)
                ret.insert(ret.end(), ret[b])->push_back(nums[i]);
        return ret;
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{ 1,2,2 };
    for (const auto &v : s.subsetsWithDup(vec))
    {
        std::cout << "[";
        for (auto i : v)
            std::cout << i << ",";
        std::cout << (v.empty() ? "]" : "\b]") << std::endl;
    }
}
