/*
 * 29. Divide Two Integers
 * Divide two integers without using multiplication,division and mod operator.
 * If it is overflow,return MAX_INT.
 */
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

#define INT_MAX    2147483647
#define INT_MIN    (-INT_MAX-1)

class Solution {
public:
    int divide(int dividend, int divisor)
    {
        long long a = dividend >= 0 ? dividend : -(long long)dividend;
        long long b = divisor >= 0 ? divisor : -(long long)divisor;
        long long result = 0, shift = 31;
        while (shift >= 0)
        {
            if (a >= b << shift)
            {
                a -= b << shift;
                result += 1LL << shift;
            }
            shift--;
        }
        result = ((dividend^divisor) >> 31) ? (-result) : (result);
        if (result > INT32_MAX) return INT32_MAX;
        else return result;
    }
};

int main()
{
    Solution s;
    cout << "0/2= " << s.divide(0, 2) << endl;
    cout << "10/3= " << s.divide(10, 3) << endl;
    cout << "10/2= " << s.divide(10, 2) << endl;
    cout << "1/-1= " << s.divide(1, -1) << endl;
    cout << "-1/-1= " << s.divide(-1, -1) << endl;
    cout << "2147483647/1= " << s.divide(2147483647, 1) << endl;
    cout << "-2147483647/1= " << s.divide(-2147483647, 1) << endl;
    cout << "2147483647/-1= " << s.divide(2147483647, -1) << endl;
    cout << "-2147483647/-1= " << s.divide(-2147483647, -1) << endl;
    cout << "2147483647/2= " << s.divide(2147483647, 2) << endl;
    cout << "2147483647/10= " << s.divide(2147483647, 10) << endl;
    //cout << "-2147483648/1=" << s.divide(-2147483648, 1) << endl;
    //cout << "-2147483648/-1=" << s.divide(-2147483648, -1) << endl;
}
