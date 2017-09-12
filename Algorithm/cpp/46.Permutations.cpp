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
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> vv;
        vv.push_back(nums);

        if (nums.size() < 2)
        {
            return vv;
        }

        int pos = 0;
        while (pos < nums.size() - 1)
        {
            int size = vv.size();
            for (int i = 0; i<size; i++)
            {
                //take each number to the first place
                for (int j = pos + 1; j < vv[i].size(); j++)
                {
                    vector<int> v = vv[i];
                    int t = v[j];
                    v[j] = v[pos];
                    v[pos] = t;
                    vv.push_back(v);
                }
            }     
            pos++;
        }
        return vv;
    }
};

int main()
{
    Solution s;
    int n = 3;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(i + 1);
    }

    vector<vector<int>>vv;
    vv = s.permute(v);

    for (int i = 0; i < vv.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << "]";
    }
    return 0;
}
