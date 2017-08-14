/*
 * 62. Unique Paths
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked
 * 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * Note: m and n will be at most 100.
 */

#include <functional>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		if (m > n)std::swap(m, n);
		if (m < 2)return m;
		std::vector<int> steps(n,1);
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				steps[j] += steps[j - 1];
		return steps[n - 1];
	}
};

int main()
{
	Solution s;
	std::cout << s.uniquePaths(3, 7) << std::endl;
	return 0;
}
