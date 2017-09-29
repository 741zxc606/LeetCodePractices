/*
 * 58.Length of Last Word
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',return the length of last word in the string.
 * If the last wird does not exist,return 0.
 * Note:A word is defined as a character sequence sonsists of non-space charaters only.
 * For example,
 * Given s="Hello World",
 * return 5.
 */

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ')
        {
            len++;
            tail--;
        }
        return len;
    }
};

int main()
{
    Solution s;
    string s1 = "a";
    string s2 = "Hello World";
    cout << s.lengthOfLastWord(s1) << endl;
    cout << s.lengthOfLastWord(s2) << endl;
    return 0;
}
