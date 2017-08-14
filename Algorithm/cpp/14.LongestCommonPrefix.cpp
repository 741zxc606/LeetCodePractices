/*
 * 14. Longest Commoon Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string>&strs)
	{
		if (strs.empty()) return "";
		for (size_t i = 0; i < strs.front().size(); ++i)
		{
			for (const auto &str : strs)
				if (i == str.size() || str.at(i) != strs.front().at(i))
					return strs.front().substr(0, i);
		}
		return strs.front();
	}
};

int main()
{
	Solution s;
	std::cout << s.longestCommonPrefix(vector<std::string>{ "hello", "helo", "heat", "hey" }) << std::endl;
	std::cout << s.longestCommonPrefix(vector<std::string>{ "partition", "party", "partner", "partake" }) << std::endl;
	return 0;
}
