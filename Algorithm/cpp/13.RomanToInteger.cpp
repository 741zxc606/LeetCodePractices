/*
 * 12. Roman to Integer
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <string>
#include <iostream>
using std::string;
using namespace std;

class Solution
{
public:
	int romantoInt(string s)
	{
		int res = 0;
		for(auto iter=s.rbegin();iter!=s.rend();++iter)
			switch (*iter)
			{
				case 'I':res += res >= 5 ? -1 : 1; break;
				case 'V':res += 5; break;
				case 'X':res += 10 * (res >= 50 ? -1 : 1); break;
				case 'L':res += 50; break;
				case 'C':res += 100 * (res >= 500 ? -1 : 1); break;
				case 'D':res += 500; break;
				case 'M':res += 1000; break;
			}
		return res;
	}
};

int main()
{
	Solution s;
	std::cout << s.romantoInt("IX") << std::endl;
	std::cout << s.romantoInt("XL") << std::endl;
	std::cout << s.romantoInt("XC") << std::endl;
	std::cout << s.romantoInt("CD") << std::endl;
	std::cout << s.romantoInt("MMXIV") << std::endl;
	std::cout << s.romantoInt("MDDCCCLXXXIV") << std::endl;
}
