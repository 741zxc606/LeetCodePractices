/*
 * 125.Valid Palindrome
 * Given a string,determine if it is a palindrome,considering only alphanumeris characters and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome. 
 * Note:
   Have you consider that the string might be empty?This is a good question to ask during an interview.
   For the pupose of this problem,we define empty string as valid palindrome.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        for (auto b = s.cbegin(), e = std::prev(s.cend()); b < e; ++b, --e)
        {
            while (!isalnum(*b)) ++b;
            while (!isalnum(*e)) --e;
            if (b < e&&tolower(*b) != tolower(*e))
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string str1 = "A man, a plan, a canal: Panama";
    std::cout << s.isPalindrome(str1) << std::endl;
    return 0;
}
