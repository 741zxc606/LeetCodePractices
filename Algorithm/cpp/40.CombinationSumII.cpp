/*
 * 40. Combination Sum II
 * Given a collection of candidate numbers(C) and a target number(T),find all unique combinations in C where the
 * candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 * Note:
 *     All numbers(including target)will be positive integers.
 *     The solution set must not contain duplicate combinations.
 * For example,giben candidate set [10,1,2,7,6,1,5] and target 8,
 * A solution set is:
 * [
 *  [1,7],
 *  [1,2,5],
 *  [2,6],
 *  [1,1,6],
 * ]
 */

#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ret;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, ret, target, vector<int>{}, 0);
        return ret;
    }

    void dfs(const vector<int> &candidates, vector<vector<int>> &ret, int target, vector<int> cur, size_t start)
    {
        if (target == 0)
        {
            ret.push_back(cur); return;
        }

        for (auto i = start; i < candidates.size(); ++i)
        {
            if (i > start&&candidates[i] == candidates[i - 1]) continue;
            else if (candidates.at(i) <= target)
            {
                cur.push_back(candidates.at(i));
                dfs(candidates, ret, target - candidates.at(i), cur, i + 1);
                cur.pop_back();
            }
            else break;
        }
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{ 10,1,2,7,6,1,5 };
    for (const auto &v : s.combinationSum2(vec, 8))
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

