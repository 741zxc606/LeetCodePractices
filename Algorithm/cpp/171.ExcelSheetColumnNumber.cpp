/*
 * 171.Excel Sheet Column Number
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * For example:
 *      A -> 1
 *      B -> 2
 *      C -> 3
 *      ...
 *      Z -> 26
 *      AA -> 27
 *      AB -> 28
 *      ...
 * Example 1:
 *      Input: "A"
 *      output: 1
 * Example 2:
 *      Input: "AB"
 *      Output: "28"
 * Example 3:
 *      Input: "ZY"
 *      Output: 701
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s)
    {
        int number = 0;
        for (const auto& c : s)
        {
            number *= 26;
            number += c - 'A' + 1;
        }
        return number;
    }
};

int main()
{
    Solution s;

    string str1 = "A";
    string str2 = "Z";
    string str3 = "AA";
    string str4 = "TESLA";

    std::cout << s.titleToNumber(str1) << std::endl;
    std::cout << s.titleToNumber(str2) << std::endl;
    std::cout << s.titleToNumber(str3) << std::endl;
    std::cout << s.titleToNumber(str4) << std::endl;
    
    return 0;
}
