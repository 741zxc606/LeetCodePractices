/*
 * 119.Pascal's Triangle II
 * Given an index k,return the Kth row of the Pascal's triangle.
 * For example,given k = 3,
 * Return [1,3,3,1].
 * 
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRom(int rowIndex)
    {
        vector<int> v(rowIndex + 1, 0);
        v[0] = 1;

        for (int i = 0; i<rowIndex; i++)
        {
            for (int j = i + 1; j>0; j--)
            {
                v[j] += v[j - 1];
            }
        }
        return v;
    }
};

void printVector(vector<int> pt)
{
    cout << "{";
    for (int j = 0; j < pt.size(); j++)
    {
        cout << pt[j] << ", ";
    }
    cout << "}" << endl;
}

int main()
{
    Solution s;
    int n = 3;
    printVector(s.getRom(n));
}
