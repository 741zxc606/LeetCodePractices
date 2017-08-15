/*
 * 27. Remove Element
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * Your function should return length = 2, with the first two elements of nums being 2.
 */

#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
	int removeElement(int A[], int n, int elem)
	{
		for (int i = 0; i < n;)
		{
			if (A[i] == elem)std::swap(A[i], A[--n]);
			else ++i;
		}
		return n;
	}
};

int main()
{
	Solution s;
	int arr0[] = {3,2,2,3};
	int arr1[] = { 1,3,4,5,3,6,8,9 };
	std::cout << s.removeElement(arr0,4,3) << std::endl;
	std::cout << s.removeElement(arr1,8,3) << std::endl;
}
