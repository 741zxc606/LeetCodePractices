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
};

int main()
{
	Solution s;
	int A1[] = { 2,3,1,1,4 };
	int A2[] = { 3,2,1,0,4 };
	
	std::cout << std::boolalpha << s.canJump(A1, 5) << std::endl;
	std::cout << std::boolalpha << s.canJump(A2, 5) << std::endl;
}


