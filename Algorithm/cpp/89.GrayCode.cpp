/*
 * 89.Gray Code
 * The gray code is a binary numeral sustem where two successive values differ in only one bit.
 * Given a non-negative integer n representing the total number of bits in the code,print the sequence of gray code.
 * A gray code sequaence must begin with 0.
 * For example, given n=2,return [0,1,3,2].Its gray code sequence is:
 *      00 - 0
 *      01 - 1
 *      11 - 3
 *      10 - 2
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * For example,[0,2,3,1] is also a valid gray code sequence according to the above definition.
 * For now,the judge is able to judge based on one instance of gray code sequence.Sorry about that.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n)
    {
        vector<int> ret;
        int size = 1 << n;
        for (int i = 0; i < size; ++i)
        {
            ret.push_back((i >> 1) ^ i);
        }
        return ret;
    }
};

void printBit(int n,int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        if (n&(1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}

void printVector(vector<int>& v, int bit_len)
{
    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); ++it)
    {
        printBit(*it, bit_len);
        cout << " ";
    }
}

int main()
{
    int n = 2;
    Solution s;
    vector<int> v = s.grayCode(n);
    printVector(v, n);
    return 0;
}
