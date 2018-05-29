/*
 * 202.Happy Number
 * Write an algorithm to determine if an number is "happy".
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the
 * squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which
 * does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 * Example: 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 */

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int squares(int n)
    {
        int result = 0;
        int sq = 0;
        for (; n > 0; n /= 10)
        {
            sq = n % 10;
            result += (sq*sq);
        }
        return result;
    }

    bool isHappy(int n)
    {
        if (n == 1) return true;

        map<int, bool> m;
        m[n] = true;

        while (n != 1)
        {
            n = squares(n);
            if (m.find(n) != m.end())
            {
                return false;
            }
            m[n] = true;
        }
        return true;
    }
};

int main(int argc,char** argv)
{
    int n = 19;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }

    Solution s;
    cout << n << (s.isHappy(n) ? " is " : " isn't ") << "a happy number" << endl;
    
    return 0;
}
