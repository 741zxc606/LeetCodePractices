/*
 * 66.Plus One
 * Given a non-negative integer represented as a non-empty array of digits,plus one to the integer.
 * You may assume the integer do not contain any leading zero,except the number 0 itself.
 * The digits are stored such that the most significant digit is at the head of the list.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int>plusOne(vector<int>& digits)
    {
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter)
            if (++*iter < 10) break;
            else *iter = 0;
        if (digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution s;
    vector<int> vec{ 9,9,9,9 };
    vec = s.plusOne(vec);
    for (auto i : vec) std::cout << i;
    std::cout << std::endl;
    return 0;
}
