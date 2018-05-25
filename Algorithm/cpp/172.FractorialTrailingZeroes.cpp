/*
 * 172.Factorial Trailing Zeroes
 * Given an integer n, return the number of trailing zeroes in n!
 * Example 1: 
 *      Input: 3
 *      Output: 0
 *      Explanation: 3! = 6, no trailing zero.
 * Example 2: 
 *      Input: 5
 *      Output: 1
 *      Explanation: 5! = 120, one trailing zero.
 * NoteL Your solution should be in logarithmix time complexity.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n)
    {
        int sum = 0;
        int tmp = 0;
        while (n / 5 > 0)
        {
            tmp = n / 5;
            sum+=tmp;
            n = tmp;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    int n0 = 3;
    int n1 = 5;
    std::cout << s.trailingZeroes(n0) << std::endl;
    std::cout << s.trailingZeroes(n1) << std::endl;

    return 0;
}
