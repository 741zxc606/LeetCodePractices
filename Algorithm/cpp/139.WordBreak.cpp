/*
 * 139.Word Break
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,determine if s can be segmented into a 
 * space-separated sequence of one or more dictionary words.You may assume the dictionary does not contain duplicate words.
 * For example,given
 * s = "leetcode",
 * dict = ["leet","code"].
 * Return true because "leetcode" can be segmented as "leet code".
 * UPDATE:
 * The wordDict parameter had been chaged to a list of strings(instead of strings).Please reload the code definition to get the 
 * lasted changes.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>&dict)
    {
        if (dict.find(s) != dict.end()) return true;
        std::vector<string::const_iterator> cache{ s.cbegin() };
        for(auto subEnd=s.cbegin();subEnd!=s.cend();++subEnd)
            for(auto subBeg:cache)
                if (subBeg < subEnd&&dict.find(string(subBeg, subEnd)) != dict.end())
                {
                    if (dict.find(string(subEnd, s.cend())) != dict.end())return true;
                    cache.push_back(subEnd); break;
                }
        return false;
    }
};

int main()
{
    Solution s;
    std::unordered_set<std::string> uset{ "Leet", "Code" };
    cout << s.wordBreak("LeetCode", uset) << endl;
    return 0;
}
