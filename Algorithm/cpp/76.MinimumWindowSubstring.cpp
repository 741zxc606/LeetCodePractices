/*
* 76.Minimum Window Substring
* Given a string S and a string T,find the minimum window in S which will contain all the characters in T in complexity O(n).
*
* For example,
* S = "ADOBECODEBANC"
* T = "ABC"
*
* Minimum window is "BANC".
*
* Note:
* If there is no such window in S that covers all characters in T,return the empty string "".
* If there are multiple such windows,you are guanranteed that there will always be only one unique minimum window in S.
*/

#include <map>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define INT_MAX 2147483647

class Solution {
public:
    string minWindow(string S, string T)
    {
        if (S.empty() || T.empty())
        {
            return "";
        }
        int count = T.size();
        int require[128] = { 0 };
        bool chSet[128] = { false };
        for (int i = 0; i < count; ++i)
        {
            require[T[i]]++;
            chSet[T[i]] = true;
        }
        int i = -1;
        int j = 0;
        int minLen = INT_MAX;
        int minIdx = 0;
        while (i < (int)S.size() && j < (int)S.size())
        {
            if (count)
            {
                i++;
                require[S[i]]--;
                if (chSet[S[i]] && require[S[i]] >= 0)
                {
                    count--;
                }
            }
            else
            {
                if (minLen > i - j + 1)
                {
                    minLen = i - j + 1;
                    minIdx = j;
                }
                require[S[j]]++;
                if (chSet[S[j]] && require[S[j]] > 0)
                {
                    count++;
                }
                j++;
            }
        }
        if (minLen == INT_MAX)
        {
            return "";
        }
        return S.substr(minIdx, minLen);
    }
};



int main()
{
    Solution s;

    string str1 = "ADOBECODEBANC";
    string str2 = "ABC";
   
    cout << "S = \"" << str1 << "\"  T=\"" << str2 << "\"" << endl;
    cout << s.minWindow(str1, str2) << endl;

    return 0;
}
