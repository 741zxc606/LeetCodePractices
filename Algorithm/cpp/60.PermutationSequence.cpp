/*
 * 60.Permutation Sequence
 * The set[1,2,3,...,n] contains a total of n!unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence(ie,for n=3):
 *      1."123"
 *      2."132"
 *      3."213"
 *      4."231"
 *      5."312"
 *      6."321"
 * Given n and k,return the K th permutation sequence.
 * Note:Given n will be between 1 and 9 inclusive.
 */

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k)
    {
        int table[10] = { 1 };
        for (int i = 1; i <= 9; ++i)
        {
            table[i] = i*table[i - 1];
        }
        string dict(n, ' '), ret(dict);
        std::iota(dict.begin(), dict.end(), '1');

        for (int i = 0; n > 0; --n)
        {
            int pos = (k - 1) / table[n - 1];
            ret[i++] = dict[pos];
            dict.erase(dict.begin() + pos);
            k = k - pos*table[n - 1];
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.getPermutation(3, 5) << endl;
    cout << s.getPermutation(4, 6) << endl;
    return 0;
}
