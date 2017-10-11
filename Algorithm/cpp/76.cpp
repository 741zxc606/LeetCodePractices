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
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        //take care of Boundary!!!
        string win;
        if (s.size()<=0||t.size()<=0|| t.size() > s.size()) return win;
        if ((s.size() == t.size()) && (s != t)) return win;
        
        vector<int> map(128, 0);
        for (auto c : t) map[c]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size())
        {
            if (map[s[end++]]-- > 0) counter--;//in t
            while (counter == 0)//valid
            {
                if (end - begin < d) d = end - (head = begin);
                if (map[s[begin++]]++ == 0) counter++;//make it invalid
            }
        }
        return d == INT_MAX ? "." : s.substr(head, d);
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
