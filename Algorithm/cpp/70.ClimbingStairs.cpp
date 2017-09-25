/*
 * 70.Climbing Stairs
 * YOu are climbing a stair case.It takes n steps to reach to the top.
 * Eacxh time you can either climb 1 or 2 steps.In how many distinct ways cam you climb the top?
 * Note:Given n will be a positive integer.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n)
    {
        if (n < 0) return 0;
        else if (n < 3) return n;
        int res = 0;
        for (int i = 0, a = 1, b = 2; i != n - 2; ++i)
        {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int n = 3;
    cout << s.climbStairs(n) << endl;
    return 0;
}
