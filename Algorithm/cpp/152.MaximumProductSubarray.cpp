/*
 * 152.Maximum Product Subarray
 * Given an interger array nums,find the contiguous subarray within an array (containing at least one number) which has largest product.
 *
 * Example 1:
 *  Input: [2,3,-2,4]
 *  Output: 6
 *  Explanation: [2,3] has the largest sum = 6.
 * 
 * Example 2:
 *  Input: [-2,0,-1]
 *  Output: 0
 *  Explanation: The result cannot be 2,because [-2,-1] is not a subarray.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums)
	{
		vector<int>f, g;
		f.push_back(nums[0]);
		g.push_back(nums[0]);
		for (int i = 1; i < nums.size(); ++i)
		{
			f.push_back(max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]));
			g.push_back(min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]));
		}
		int m = f[0];
		for (int i = 1; i < f.size(); ++i)
			m = max(m, f[i]);
		return m;
	}
};

int main()
{
	Solution s;
	int arr1[] = { 2,3,-2,4 };
	int arr2[] = { -2,0,-1 };
	vector<int> nums1(begin(arr1), end(arr1));
	vector<int> nums2(begin(arr2), end(arr2));

	std::cout << s.maxProduct(nums1) << std::endl;
	std::cout << s.maxProduct(nums2) << std::endl;
}
