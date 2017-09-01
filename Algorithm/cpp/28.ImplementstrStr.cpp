/*
* 28. Implement strStr()
* Implement strStr().
* Return the index of the first occurrence of needle in haystack,or -1 if needle is not part of haystack.
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    //KMP Algorithm
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }

        return KMP(haystack, needle);
    }

    int KMP(const string& text,const string& pattern)
    {
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i)
        {
            while (j > -1 && pattern[j + 1] != text[i])
            {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i])
            {
                ++j;
            }
            if (j == pattern.length() - 1)
            {
                return i-j;
            }
        }
        return -1;
    }

    vector<int> getPrefix(const string& pattern)
    {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i)
        {
            while (j > -1 && i < pattern[j + 1] != pattern[i])
            {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i])
            {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};

int main()
{
    string haystack = "Iamyourfather";
    string needle = "you";
    Solution s;
    std::cout << s.strStr(haystack, needle) << std::endl;
}
