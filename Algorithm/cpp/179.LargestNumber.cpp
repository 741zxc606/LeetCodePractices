/*
 * 179.Largest Number
 * Given a list of non negative integers, arrange them such that they form te largest number.
 * Example 1: 
 *      Input: [10,2]
 *      Output: "210"
 * Example 2: 
 *      Input: [3,30,34,5,9]
 *      Output: "9534330"
 * Notw: The result may be very large, so you need to return a string instead of an integer.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
    //compare function
    static bool comp(string& s1, string& s2) { return s1 + s2 > s2 + s1; }

    string largestNumber(vector<int>& nums)
    {
        //convert int to string
        vector<string>v;
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back(to_string(nums[i]));
        }

        //sort the string
        sort(v.begin(), v.end(), comp);

        //generate the result
        string result;
        for (int i = 0; i < v.size(); i++)
        {
            result += v[i];
        }

        //special case: start with zero (e.g. [0,0])
        if (result[0] == '0')return "0";

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> a1{ 10,2 };
    vector<int> a2{ 3,30,34,5,9 };

    std::cout << s.largestNumber(a1) << std::endl;
    std::cout << s.largestNumber(a2) << std::endl;

    return 0;
}
