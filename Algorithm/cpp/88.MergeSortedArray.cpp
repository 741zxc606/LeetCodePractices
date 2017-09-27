/*
 * 88.Merge Sorted Array
 * Given two sorted integer arrays nums1 and nums2,merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n)
    {
        int ia = m - 1, ib = n - 1, i = m + n - 1;
        for (int i = m + n - 1; i >= 0; i--)
        {
            if (ia >= 0 && ib < 0)
            {
                break;
            }
            if (ia < 0 && ib >= 0)
            {
                A[i] = B[ib--];
                continue;
            }
            if (ia >= 0 && ib >= 0)
            {
                if (A[ia] > B[ib])
                {
                    A[i] = A[ia--];
                }
                else 
                {
                    A[i] = B[ib--];
                }
            }
        }
    }
};

void printArray(int num[], int n)
{
    printf("{");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", num[i]);
    }
    printf("}\n");
}

int main()
{
    Solution s;
    
    int a[]={ 1,4,6,9,12 };
    int b[]={ 3,7,8,10,13 };

    s.merge(a, 5, b, 5);
    printArray(a, sizeof(a) / sizeof(int));
        
    return 0;
}
