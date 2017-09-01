/*
 * 26. Remove Duplicates from Sorted Array
 * Given a sorted array,remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array,you must do this in place with constant memory.
 * For exmaple,
 * Given input array nums=[1,1,2],
 * Your function should return length =2 ,with the first two element of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n <= 1) return n;

        int pos = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] != A[i + 1])
            {
                A[++pos] = A[i + 1];
            }
        }
        return pos + 1;
    }
};

int main()
{
    Solution s;
    int a1[] = {1,1,2};
    std::cout << s.removeDuplicates(a1,3) << std::endl;
}
