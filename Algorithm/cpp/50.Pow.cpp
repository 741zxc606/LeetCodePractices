/*
 * 50.Pow(x,n)
 * Implement pow(x,n).
 * x^n
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n)
    {
        if (n == 0) return 1;
        double t = myPow(x, n / 2);
        if (n % 2) return n < 0 ? 1 / x*t*t : x*t*t;
        else return t*t;
    }
};

int main()
{
    Solution s;
    cout << s.myPow(3.5, 6) << endl;
    cout << s.myPow(3.5, 0) << endl;
    cout << s.myPow(0, 6) << endl;
    cout << s.myPow(-5, 5) << endl;
    cout << s.myPow(-5, -5) << endl;
    return 0;
}
