/*
 * 91.Decode Ways
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *   'A' -> 1
 *   'B' -> 2
 *   ...
 *   'Z' -. 26
 * Gicen an encoded message containing digits,determine the total number of ways to decode it.
 * For example,
 * Given encoded message "12",it could be decoded as "AB" (1 2) or "L" (12).
 * The number of ways decoding "12" is 2.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int check(char ch)
    {
        //check 0 or not
        return (!isdigit(ch) || ch == '0') ? 0 : 1;
    }

    int check(char ch1, char ch2)
    {
        //check it is between 10 and 26
        return (ch1 == '1' || (ch1 == '2'&&ch2 <= '6')) ? 1 : 0;
    }

    int numDecodings(string s)
    {
        if (s.size() <= 0) return 0;
        if (s.size() == 1) return check(s[0]);

        int* dp = new int[s.size()];
        memset(dp, 0, s.size() * sizeof(int));

        dp[0] = check(s[0]);
        dp[1] = check(s[0])*check(s[1]) + check(s[0], s[1]);
        for (int i = 2; i < s.size(); i++)
        {
            if (!isdigit(s[i])) break;
            if (check(s[i]))
            {
                dp[i] = dp[i - 1];
            }
            if (check(s[i - 1], s[i]))
            {
                dp[i] += dp[i - 2];
            }
        }
        int result = dp[s.size() - 1];
        delete[] dp;
        return result;
    }
};

int main()
{
    Solution s;
    string s1 = "123";
    cout << "\"" << s1 << "\":" << s.numDecodings(s1) << endl;
    return 0;
}
