/*
 * 151.Reverse words in a String
 * Given an input string,reverse the string word by word.
 * Example:
 *  Input:"the sky is blue",
 *  Output:"blue is sky the".
 *
 * Notes:
 * 1.A word is defined as a sequence of non-space charaters.
 * 2.Input string may contain leading or trailing spaces.However,your reversed string should not contain leading or training spaces.
 * 3.You need to reduce multiple spaces between two words to a single in the reversed string.
 *
 * Follow up:For C programmers,try to solve it in-place O(1) space.
 */

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void reverseWords(string &s)
	{
		if (s.length() == 0) return;
		
		string result = "";
		if (s[s.length() - 1] == ' ')
		{
			int last = s.find_last_not_of(' ') + 1;
			s.erase(last, s.length() - last);
		}

		int first = s.find_first_not_of(' ', 0);
		while (first != string::npos)
		{
			int wend = s.find(' ', first);//word end
			if (wend == string::npos) wend = s.length();

			string word = s.substr(first, wend - first);
			reverse(word.begin(), word.end());
			result += word;

			first = s.find_first_not_of(' ', wend);//next word
			if (first == string::npos) break;

			result += ' ';
		}
		reverse(result.begin(), result.end());
		s.swap(result);
	}
};

int main()
{
	Solution a;

	string s = "the sky is blue";
	a.reverseWords(s);
	std::cout << s << std::endl;
}
