/*
 * 77.Combinations
 * Given two integers n and k,return all possible combinations of k numbers out of 1...n.
 * For example,
 * If n = 4 and k = 2,a solution is:
 * [
 *  [2,4],
 *  [3,4],
 *  [2,3],
 *  [1,2],
 *  [1,3],
 *  [1,4],
 * ]
 */

#include <vector>
#include <functional>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> retv;
        vector<int> vec(k);
        function<void(int, int, int)> combine = [&](int i, int n, int k)
        {
            for (int j = k - 1; i > 0; j ? combine(i, n, j) : retv.push_back(vec))
                vec[j] = i--;
        };
        combine(n, n, k);
        return retv;
    }
};

int main()
{
    Solution s;
    for (const auto &v : s.combine(4, 2))
    {
        std::cout << "[";
        for (auto i : v)
            std::cout << i <<" ";
        std::cout << "]" << std::endl;
    }
    return 0;
}
