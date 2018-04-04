/*
 * 136.Single Number
 * Given an array of integers,every elements appears twice except for one.
 * Find out that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n)
	{
		int r{ 0 };
		for (int i = 0; i != n; ++i)
			r ^= A[i];
		return r;
	}
};

int main()
{
	Solution s;
	int A[7] = { 1,2,3,4,3,2,1 };
	std::cout << s.singleNumber(A, 7) << std::endl;
}
