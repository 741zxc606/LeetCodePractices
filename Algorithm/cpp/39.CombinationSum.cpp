/*
 * 39. Combination Sum
 * Given a set of candidate numbers(C)(without duplicates) and a target number(T),find all unique combinations in C where the
 * candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 *     All numbers (including target) will be positive integers.
 *     The solution set must not contain duplicate combinations.
 *
 * For example,given candidate set [2,3,6,7] and target 7,
 * A solution set is:
 * [
 *  [7],
 *  [2,2,3]
 * ]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ret;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, vector<int>{}, 0, ret);
        return ret;
    }

    void dfs(const vector<int> &cdds, int target, vector<int> curr, size_t index, vector<vector<int>>&ret)
    {
        if (!target) 
        {
            ret.push_back(curr); 
            return;
        }
        for (auto i = index; i < cdds.size(); ++i)
            if (cdds[i] <= target)
            {
                curr.push_back(cdds[i]);
                dfs(cdds, target - cdds[i], curr, i, ret);
                curr.pop_back();
            }
            else break;
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{ 2,3,6,7 };
    for (const auto &v : s.combinationSum(vec, 7))
    {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}
