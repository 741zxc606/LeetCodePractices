/*
 * 43. Multiply Strings
 * Given two non-negative integers num1 and num2 represented as strings,return the product of num1 and num2.
 * Note:
 *     1.The length of both num1 and num2 is < 110.
 *     2.Both num1 and num2 contains only digits 0-9.
 *     3.Both num1 and num2 does not contain any leading zero.
 *     4.You must not use any bulit-in BigInterger library or convert the inputs to integer directly.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2)
    {
        string ret(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                int sum = (ret[i + j + 1] - '0') + (num1[i] - '0')*(num2[j] - '0') + carry;
                ret[i + j + 1] = sum % 10 + '0';
                carry = sum / 10;
            }
            ret[i] += carry;
        }
        size_t pos = ret.find_first_not_of('0');
        if (pos != string::npos) return ret.substr(pos);
        else return "0";
    }
};

int main()
{
    Solution s;
    cout << s.multiply("442", "1993") << endl;
    return 0;
}
