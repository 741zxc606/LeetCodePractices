/*
 * 1.Two Sum
 * Given an array of intergers,return indices of two numbers such that they add up to a specific target.
 * You may asssume that each input would have exactly one solution,and you not use the same element twice.
 * Example:
 * Given nums = [2,7,11,15],target = 9, 
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0,1].
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		unordered_map<int, int>m;
		vector<int> result;
		for (int i=0;i<numbers.size();i++)
		{
			if (m.find(numbers[i]) == m.end())
			{
				m[target - numbers[i]] = i;
			}
			else
			{
				result.push_back(m[numbers[i]]);
				result.push_back(i);
				break;
			}
		}
		return result;
	}
};

int main()
{
	int nums[] = {2,7,11,15};
	int target = 9;
	vector<int> n(begin(nums),end(nums));
	vector<int> Index = Solution().twoSum(n,target);
	cout << Index[0] << endl;
	cout << Index[1] << endl;
	return 0;
}
