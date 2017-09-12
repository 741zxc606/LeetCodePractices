/*
* 46. Permutations
* Given a collection of distinct numbers, return all possible permutations.
* For example,
* [1,2,3] have the following permutations:
* [
*   [1,2,3],
*   [1,3,2],
*   [2,1,3],
*   [2,3,1],
*   [3,1,2],
*   [3,2,1]
*  ]
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        do {
            ret.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> vec{ -1,0,1 };
    for (auto v : s.permute(vec))
    {
        cout << "[";
        for (auto i : v)
            cout << i << " ";
        cout << "]"<< endl;
    }
    return 0;
}
