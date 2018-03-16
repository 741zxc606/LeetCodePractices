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
	vector<vector<string>>ret;
public:
	using cIter = string::const_iterator;
	vector<vector<string>>partition(string s)
	{
		vector<string>v;
		partition(s.cbegin(), s.cend(), v);
		return ret;
	}
	void partition(cIter beg, cIter end, vector<string> &v)
	{
		if (beg == end)
		{
			ret.push_back(v);
			return;
		}
		for(auto it=beg;it!=end;++it)
			if (isPalindrome(beg, it))
			{
				v.emplace_back(beg, std::next(it));
				partition(std::next(it), end, v);
				v.pop_back();
			}
	}
	bool isPalindrome(cIter first, cIter last)
	{
		for (; first < last; ++first, --last)
			if (*first != *last)return false;
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
