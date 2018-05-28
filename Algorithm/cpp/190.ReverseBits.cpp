/*
 * 190.Reverse Bits
 * Reverse bits of a given 32 bits ubsigned integer.
 * Example:
 *      Input: 43261596
 *      Output: 964176192
 *      Explanation: 43261596 represented in binary as 00000010100101000001111010011100,
 *                   return 964176192 represented in binary as 00111001011110000010100101000000.
 * Follow up:
 * If this function is called many times, how would you optimize it?
 */

#include <iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ret = 0;
        for (int i = 0; i < 32; i++)
        {
            ret = (ret * 2) + (n & 0x1);
            n /= 2;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    uint32_t n = 43261596;
    cout << s.reverseBits(n) << endl;
    return 0;
}
