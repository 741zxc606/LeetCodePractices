/*
* 53.Maximum Subarray
* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
* For example,given the array [-2,1,-3,4,-1,2,1,-5,4],
* the configuous subarray [4,-1,2,1] has the largest sum = 6.
*
* More practice:
* If you have figured out the O(n) solution,try coding another solution using the divide and conquer approach,
* which is more subtle.
*/

/* Divide Conquer */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    int maxCrossing(int A[], int l, int m, int h)
    {
        int left_max = INT_MIN, right_max = INT_MIN;
        for (int i = m, sum = 0; i >= 1; --i)
        {
            sum += A[i];
            if (left_max < sum) left_max = sum;
        }
        for (int i=m+1,sum=0;i<=h;++i)
        {
            sum += A[i];
            if (right_max < sum) right_max = sum;
        }
        return left_max + right_max;
    }

    int maxSubArray(int A[], int l, int h)
    {
        if (l == h) return A[l];
        int m = (l + h) / 2;
        return std::max({ maxSubArray(A,l,m),maxSubArray(A,m + 1,h),maxCrossing(A,l,m,h) });
    }

public:
    int maxSubArray(int A[], int n)
    {
        return maxSubArray(A, 0, n - 1);
    }
};

int main()
{
    int A[]={ -2,1,-3,4,-1,2,1,-5,4 };
    Solution s;
    cout << s.maxSubArray(A, 9) << endl;
    return 0;
}
