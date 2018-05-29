/*
 * 204. Count Primes
 * Count the number of prime numbers less than a non-negative number, n.
 * Example:
 *      Input: 10
 *      Output: 4
 *      Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n)
    {
        vector<bool> isPrimer(n, true);

        for (int i = 2; i*i < n; i++)
        {
            if (isPrimer[i])
            {
                for (int j = i*i; j < n; j += i)
                {
                    isPrimer[j] = false;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrimer[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(int argc, char**argv)
{
    int n = 100;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }

    Solution s;
    cout << endl << n << ":" << s.countPrimes(n) << endl;

    return 0;
}
