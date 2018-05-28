/*
 * 191. Number of 1 Bits
 * Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
 * Example 1: 
 *      Input: 11
 *      Output: 3
 *      Explanation: Integer 11 has binary representatino 00000000000000000000000000001011 
 * Example 2:
 *      Input: 128
 *      Output: 1
 *      Explanation: Integer 128 has binary representation 00000000000000000000000010000000
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        for (; n > 0; n /= 2)
        {
            if (n & 0x1) cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution s;

    uint32_t n1 = 11;
    uint32_t n2 = 128;

    cout << s.hammingWeight(n1) << endl;
    cout << s.hammingWeight(n2) << endl;

    return 0;
}
