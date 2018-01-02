/*
 * 140.Word Break II
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,add spaces in s to construct a sentence
 * where each word is a valid dictionary word.You may assume the dictionary does not contain duplicate words.
 * Return all such possible sentences.
 * For example,given
 * s = "catsanddog",
 * dict = ["cat","cats","and","sand","dog"].
 * A solution is ["cats and dog","cat sand dog"].
 * UPDATE:
 * The wordDict parameter had been changed to a list of strings(instead of a set strings).Please reload the code definition to get the
 * lastest changes.
 */

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string>wordBreak(string s, unordered_set<string>& wordDict)
    {
        const int n = s.length();

        size_t max_len = 0;
        for (const auto& str : wordDict)
        {
            max_len = max(max_len, str.length());
        }

        vector<bool> canBreak(n + 1, false);
        vector<vector<bool>> valid(n, vector<bool>(n, false));
        canBreak[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int l = 1; l < max_len&&i - 1 >= 0; ++l)
            {
                if (canBreak[i - 1] && wordDict.count(s.substr(i - 1, l)))
                {
                    valid[i - l][i - 1] = true;
                    canBreak[i] = true;
                }
            }
        }

        vector<string> result, path;
        if (canBreak[n])
        {
            wordBreakHelper(s, valid, 0, &path, &result);
        }
        return result;
    }

    void wordBreakHelper(const string& s, const vector<vector<bool>>& valid, int start, vector<string> *path, vector<string> *result)
    {
        if (start == s.length())
        {
            string tmp;
            for (const auto& str : *path)
            {
                tmp += str;
                tmp += " ";
            }
            tmp.pop_back();
            result->emplace_back(move(tmp));
            return;
        }
        for (int i = start; i < s.length(); ++i)
        {
            if (valid[start][i])
            {
                path->emplace_back(s.substr(start, i + 1 - start));
                wordBreakHelper(s, valid, i + 1, path, result);
                path->pop_back();
            }
        }
    }
};

void printVector(vector<string>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

int main()
{
    Solution a;

    std::unordered_set<std::string> dict{ "cat", "cats", "and", "sand", "dog" };
    string s = "catsanddog";

    vector<string>v = a.wordBreak(s, dict);
    printVector(v);
    return 0;
}
