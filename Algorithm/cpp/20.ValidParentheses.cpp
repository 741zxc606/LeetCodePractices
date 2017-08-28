/*
 * 20. Valid Parentheses
 * Given a string containing just the characters '(',')','{','}','[',']',determine if the input string is valid.
 * The brackets must close in the correct order,"()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		const unordered_map<char, char> symbol_pail = 
		{
			{')','('},
			{']','['},
			{'}','{'}
		};
		stack<char> parentheses;
		for (const auto& c : s)
		{
			const auto& it = symbol_pail.find(c);
			if (it != symbol_pail.cend())
			{
				if (parentheses.empty() || parentheses.top() != it->second)
				{
					return false;
				}
				parentheses.pop();
			}
			else
			{
				parentheses.emplace(c);
			}
		}
		return parentheses.empty();
	}
};

int main()
{
	Solution S;
	string s1 = "{[}]";
	string s2 = "()[]{}";
	std::cout << std::boolalpha << S.isValid(s1) << std::endl;
	std::cout << std::boolalpha << S.isValid(s2) << std::endl;
}
