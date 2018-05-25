/*
 * 169.Majority Element
 * Given ana array of size n, find the majority element. The majority element is the element that appears more than [n/2] times.
 * You may assume that the array is non-empty and the majority always exist in the array.
 * Example 1:
 *  Input: [3,2,3]
 *  Output: 3
 * Example 2:
 *  Input: [2,2,1,1,1,2,2]
 *  Output: 2
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int majority;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                majority = nums[i];
                cnt++;
            }
            else
            {
                majority == nums[i] ? cnt++ : cnt--;
                if (cnt > nums.size() / 2)return majority;
            }
        }
        return majority;
    }
};

vector<int> &split(const string &s, char delim, vector<int>&elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(atoi(item.c_str()));
    }
    return elems;
}

vector<int> split(const string &s, char delim)
{
    vector<int>elems;
    split(s, delim, elems);
    return elems;
}

int main(int argc, char** argv)
{
    Solution s;
    string array = "3,2,3";
    if (argc > 1)
    {
        array = argv[1];
    }

    cout << "[" << array << "]" << endl;
    vector<int>nums = split(array, ',');
    cout << s.majorityElement(nums) << endl;

    return 0;
}
