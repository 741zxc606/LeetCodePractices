/*
* 33.Search in Rotated Sorted Array
* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
* (i.e.,0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* You are given a target value to search.If found in the array return its index,otherwise return -1.
* You may assume no duplicate exists in the array.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int find(vector<int> &A, int l, int r, int target)
    {
        if (l > r)
        {
            return -1;
        }
        int idx = -1;
        if (A[l] <= A[r])
        {
            int left = l, right = r, mid = 0;
            while (left <= right)
            {
                mid = (left + right) >> 1;
                if (A[mid] == target)
                {
                    idx = mid;
                    break;
                }
                else if (A[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        else
        {
            int mid = (l + r) >> 1;
            if (A[mid] == target)
            {
                idx = mid;
            }
            else
            {
                idx = find(A, l, mid - 1, target);
                idx = idx == -1 ? find(A, mid + 1, r, target) : idx;
            }
        }
        return idx;
    }

public:
    int search(vector<int> &A, int target)
    {
        int n = A.size();
        return find(A,0,n-1,target);
    }
};

int main()
{
    Solution s;
    int arr1[]= { 3,1 };
    int arr2[] = {0,1,2,4,5,6,7};
    vector<int> A1 (begin(arr1),end(arr1));
    vector<int> A2 (begin(arr2),end(arr2));
    cout << s.search(A1, 3) << endl;
    cout << s.search(A2, 4) << endl;
    cout << s.search(A2, 3) << endl;
    return 0;
}
