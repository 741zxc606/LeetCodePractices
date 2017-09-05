/*
 * 30. Substring with Concatenation of All Words
 * You are given a string,s,and a list of words,that are all of the same length.Find all string indicies of sustring(s)
 * in s that is a concatenation of each word in words exactly once and without any intervening charavters.
 * For example,given:
 * s:"barfoothefoobarman"
 * words:["foo","bar"]
 * You should return the indices:[0,9]
 * (order does not matter)
 */

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>&words)
    {
        vector<int> result;
        if (s.size() <= 0 || words.size() <= 0)
        {
            return result;
        }

        int n = s.size(), m = words.size(), l = words[0].size();
        
        //put all of words into a map
        map<string, int> expected;
        for (int i = 0; i < m; i++)
        {
            if (expected.find(words[i]) != expected.end())
            {
                expected[words[i]]++;
            }
            else
            {
                expected[words[i]] = 1;
            }
        }

        for (int i = 0; i < l; i++)
        {
            map<string, int> actual;
            int count = 0;//tatol count
            int winLeft = i;
            for (int j = i; j <= n - 1; j += l)
            {
                string word = s.substr(j, l);
                //if not found,then restart from j+1
                if (expected.find(word) == expected.end())
                {
                    actual.clear();
                    count = 0;
                    winLeft = j + l;
                    continue;
                }
                count++;
                //count the number of "word"
                if (actual.find(word) == actual.end())
                {
                    actual[word] = 1;
                }
                else
                {
                    actual[word]++;
                }
                //if there is more appearance of "word" than expected
                if (actual[word] > expected[word])
                {
                    string tmp;
                    do
                    {
                        tmp = s.substr(winLeft, l);
                        count--;
                        actual[tmp]--;
                        winLeft += l;
                    } while (tmp != word);
                }

                //if total count equals words's size,find one result
                if (count == m)
                {
                    result.push_back(winLeft);
                    string tmp = s.substr(winLeft, l);
                    actual[tmp]--;
                    winLeft += l;
                    count--;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution S;
    string s = "barfoobarfoothefoobarman";
    vector<string>words;
    words.push_back("foo");
    words.push_back("bar");

    vector<int> indices = S.findSubstring(s, words);
    for (int i = 0; i < indices.size(); i++)
    {
        cout << indices[i] << " ";
    }
    cout << endl;

    return 0;
}
