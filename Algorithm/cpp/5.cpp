/*
 * 5.1 Longest Palindromic Substring
 * Given a string s,find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
 * Example:
 *  Input: "babad"
 *  Output: "bab"
 *  Note:"aba" is also a valid answer.
 * Example:
 *  Input: "abbd"
 *  Output: "bb"
 */

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

//Manacher's Algorithm
class Solution
{
public:
	string longestPalindrome(string s)
	{
		string str = "", ans = "";
		int len = s.length();
		int maxl = -1, cnt;
		for (int i = 0; i < len; i++)
		{
			str += '#';
			str += s[i];
		}
		str += '#';

		for (int i = 1; i < 2 * len; i++)
		{
			cnt = 0;
			while ((i - cnt >= 0) && (i + cnt <= 2 * len) && (str[i - cnt] == str[i + cnt]))
				cnt++;
			cnt--;
			if (cnt > maxl)
			{
				maxl = cnt;
				ans = s.substr((i-cnt)/2,(i+cnt)/2-(i-cnt)/2);
			}
		}
		return ans;
	}
};

int main()
{
	Solution s;
	string s1 = "abaxdfgdcaba";
	cout << "the longest palindrome substring is:" << s.longestPalindrome(s1) << endl;
}
