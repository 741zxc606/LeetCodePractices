/*
 * 115.Distinct Subdequences
 * Given a string S and a string T,count the number of distinct subsequences of S which equals T.
 * A subsequence of string is a new string which is formed from the original string by deleting some (can be none)
 * of the characters without distubing the relative positions of the remaining characters.(ie."ACE" is a subsequence of "ABCDE" while "AEC" is not).
 * Here is  an example:
 * S = "rabbbit",T = "rabbit"
 * Return 3.
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t)
    {
        int m = t.length();
        int n = s.length();
        if (m > n) return 0;//impossible for subsequence
        vector<vector<int>> path(m + 1, vector<int>(n + 1, 0));
        for (int k = 0; k <= n; k++) path[0][k] = 1;//initialization

        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                path[i][j] = path[i][j - 1] + (t[i - 1] == s[j - 1] ? path[i - 1][j - 1] : 0);
            }
        }
        return path[m][n];
    }
};

int main()
{
    Solution z;
    string s = "rabbbit";
    string t = "rabbit";
    cout << z.numDistinct(s, t) << endl;
}
