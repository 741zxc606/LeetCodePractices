/*
 * 166.Fraction to Recurring Decimal
 * Given two integers representing the numerator and denominator of a fration, return the fraction in string format.
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * Example 1:
 *  Input: numerator = 1, denominator = 2
 *  Output: "0.5"
 * Example 2:
 *  Input: numerator = 2, denominator = 1
 *  Output: "2"
 * Example 3:
 *  Input: numerator = 2, denominator = 3
 *  Output: "0.(6)"
 */

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string result;

        if (denominator == 0) { return result; }
        if (numerator == 0) { return "0"; }

        //using long long type make sure there is no integer overflow
        long long n = numerator;
        long long d = denominator;

        //deal with negative cases
        bool sign = ((float)numerator/denominator >= 0);
        if (n < 0) { n = -n; }
        if (d < 0) { d = -d; }
        if (sign == false)
        {
            result.push_back('-');
        }

        long long remainder = n % d;
        long long division = n / d;
        ostringstream oss;
        oss << division;
        result += oss.str();
        if (remainder == 0)
        {
            return result;
        }

        //remainder has value, the result is a float
        result.push_back('.');

        //using a map to record all of remainders and their position.
        //if the remainder appeared before, which means the repeated loop begin,
        //then, get the place from map to insert "(".
        //In C++ 11, it's better to use unordered_map. 
        map<long long, int>rec;

        for (int pos = result.size(); remainder != 0; pos++, remainder = (remainder * 10) % d)
        {
            if (rec.find(remainder) != rec.end())
            {
                result.insert(result.begin() + rec[remainder], '(');
                result.push_back(')');
                return result;
            }
            rec[remainder] = pos;
            result.push_back((remainder * 10) / d + '0');
        }
        return result;
    }
};

void test(int num, int deno)
{
    Solution s;
    cout << "numerator: " << num << "\t denominator: " << deno << "\t result: " << s.fractionToDecimal(num, deno) << endl;
}

int main(int argc,char** argv)
{
    test(1, 2);
    test(2, 1);
    test(2, 3);

    if (argc > 2)
    {
        int num = atoi(argv[1]);
        int deno = atoi(argv[2]);
        test(num, deno);
    }
    return 0;
}
