/*
 * 17. Letter Combinations of a Phone Number
 * Given a digit string ,return all possible leter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * Input:Gigit string "23"
 * Output:["ad","ae","af","bd","be","bf","cd","ce","cf"].
 * Note:
 * Although the above answer is in lexicographical order,your answer could be in any order you want.
 */

#include <string>
#include <array>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> ret{""};
		array<string, 10> map{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		for (auto digit : digits)
		{
			vector<string>tmp;
			for (auto c : map[digit - '0'])
				for (const auto &pre : ret)
					tmp.push_back(pre+c);
			ret = tmp;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	for (const auto &str : s.letterCombinations("23"))
	{
		std::cout << str << std::endl;
	}
}
