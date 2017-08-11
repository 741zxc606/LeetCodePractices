/*
 * 55. Jump Game
 * Given an array of non-negative integers, you are initially positioned at the first index of the array. 
 * Each element in the array represents your maximum jump length at that position. 
 * Determine if you are able to reach the last index. 
 * For example:
 * A = [2,3,1,1,4], return true. 
 * A = [3,2,1,0,4], return false.
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool canJump(int A[], int n)
	{
		for (int i = 0, max = 0; i <= max; ++i)
			if ((max = std::max(max, i + A[i])) >= n - 1) return true;
		return false;
	}

	bool canJump2(int A[], int n)
	{
		if (n <= 0)return false;
		//
		int coverPos = 0;
		//
		for (int i = 0; i <= coverPos&&i < n; i++)
		{
			if (coverPos < A[i] + i)
			{
				coverPos = A[i] + i;
			}
			if (coverPos >= n - 1)
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	int A1[] = { 2,3,1,1,4 };
	int A2[] = { 3,2,1,0,4 };

	std::cout << std::boolalpha << s.canJump(A1, 5) << std::endl;
	std::cout << std::boolalpha << s.canJump(A2, 5) << std::endl;

	std::cout << std::boolalpha << s.canJump2(A1,5) << std::endl;
	std::cout << std::boolalpha << s.canJump2(A2,5) << std::endl;
}
