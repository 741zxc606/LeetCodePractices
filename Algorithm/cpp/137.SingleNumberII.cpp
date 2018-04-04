/*
 * 137.Single Number II
 * Given an array of integers,every element appears three times except for one,which appears exactly once.
 * Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory?
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(int A[],int n)
	{
		int low = 0;
		for (int i = 0, high = 0; i != n; ++i)
		{
			low ^= A[i] & ~high;
			high ^= A[i] & ~low;
		}
		return low;
	}
};

int main()
{
	Solution s;
	int A[7] = { 2,3,3,1,5,2,3 };
	std::cout << s.singleNumber(A, 7) << std::endl;
}
