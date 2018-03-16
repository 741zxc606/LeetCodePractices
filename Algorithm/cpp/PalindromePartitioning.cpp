/*
* 131.Palindrome Partitioning
* Given a string s,partition s such that every substring of the partition is a palindrome.
* Return all possible palindrome partitioning of s.
* For example,given a = "aab",
* Return
* [
*  ["aa","b"],
*  ["a","a","b"]
* ]
*/

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>>ret;
		if (s.empty())return ret;

		vector<string> path;
		DFS(0, s, path, ret);

		return ret;
	}

	void DFS(int index, string& s, vector<string>& path, vector<vector<string>>& ret)
	{
		if (index == s.size())
		{
			ret.push_back(path);
			return;
		}
		for (int i = index; i < s.size(); ++i)
		{
			if (isPalindrome(s, index, i))
			{
				path.push_back(s.substr(index, i - index + 1));
				DFS(i + 1, s, path, ret);
				path.pop_back();
			}
		}
	}

	bool isPalindrome(const string& s, int start, int end)
	{
		while (start <= end)
		{
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	for (const auto &v : s.partition("aab"))
	{
		for (const auto &s : v)
		{
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
}
