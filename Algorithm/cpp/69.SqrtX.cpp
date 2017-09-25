/*
 * 69.SqrtX
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 0) return 0;
        double last = 0;
        double res = 1;
        while (res != last)
        {
            last = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};

int main()
{
    int n = 64;
    Solution s;
    cout << "sqrt(" << n << ")=" << s.mySqrt(n) << endl;
    return 0;
}
