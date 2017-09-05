/*
 * 32. Longest Valid Parentheses
 * Given a string containing just the chatacters '(' and ')',find the length of the longest valis(well-formed) parentheses substring.
 *
 * For "(()",the longest valid paratheses substring is "()",which has length = 2.
 * Another ecample is ")()())",where the longest valid paratheses substring is "()()",which has length = 4.
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int maxLen = 0;
        int lastError = -1;
        vector<int> stack;
        for (int i = 0; i<s.size(); i++) 
        {
            if (s[i] == '(')
            {
                stack.push_back(i);
            }
            else if (s[i] == ')') 
            {
                if (stack.size()>0) 
                {
                    stack.pop_back();
                    int len;
                    if (stack.size() == 0) 
                    {
                        len = i - lastError;
                    }
                    else
                    {
                        len = i - stack.back();
                    }

                    if (len > maxLen) 
                    {
                        maxLen = len;
                    }
                }
                else 
                {
                    lastError = i;
                }
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution S;
    string s = ")()())";
    cout << s << ":" << S.longestValidParentheses(s) << endl;
    return 0;
}
