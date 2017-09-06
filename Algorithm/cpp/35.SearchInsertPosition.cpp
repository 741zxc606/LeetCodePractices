/*
 * 35. Search Insert Position
 * Given a sorted array and a target value,return the index if the target is found.
 * If not,return the index where it be if were inserted in order.
 * You may assume no duplicates in the array.
 * Here are few examples:
 * [1,3,5,6] 5->2
 * [1,3,5,6] 2->1
 * [1,3,5,6] 7->4
 * [1,3,5,6] 0->0
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& A, int target)
    {
        if (A.size() == 0)
        {
            return 0;
        }

        int start = 0, end = A.size() - 1;
        while (start + 1 < end)
        {
            int mid = (end - start) / 2 + start;
            if (A[mid] >= target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        if (A[start] >= target)
        {
            return start;
        }
        if (A[end] >= target)
        {
            return end;
        }

        return A.size();
    }
};

int main()
{
    int a[] = { 1,3,5,6 };
    vector<int> A(begin(a), end(a));

    Solution s;

    cout << s.searchInsert(A, 0) << endl;
    cout << s.searchInsert(A, 2) << endl;
    cout << s.searchInsert(A, 5) << endl;
    cout << s.searchInsert(A, 7) << endl;
}
