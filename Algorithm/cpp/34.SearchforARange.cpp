/*
 * 34. Search for a Range
 * Given an array of integers sorted in ascending order,find the starting and ending position of a given tarfet value.
 * Your algorithm's suntime complexity must be in the order of O(log n).
 * If the target is not found in the array,return [-1,-1].
 * For example,
 * Given [5,7,7,8,8,10] and target value 8,
 * return [3,4].
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

        /*
        *   O(log n) solution must be something like binary search.        
        *   So, we can use the binary search to find the one postion - `pos`        
        *   then, we can keep using the binary search find the target in A[0..pos-1] and A[pos+1..n]       
        *   The code below is self-explaination
        */
    vector<int> searchRange(vector<int> &A, int target)
    {
        vector<int> ans;
        int ansl = -1;
        for (int l = 0, r = A.size() - 1; l <= r;)
        {
            int mid = l + (r - l) / 2;
            if (A[mid] > target)
            {
                r = mid - 1;
            }
            if (A[mid] < target)
            {
                l = mid + 1;
            }
            if (A[mid] == target)
            {
                ansl = mid;
                r = mid - 1;
            }
        }

        int ansr = -1;
        for (int l = 0, r = A.size() - 1; l <= r;)
        {
            int mid = l + (r - l) / 2;
            if (A[mid] > target)
            {
                r = mid - 1;
            }
            if (A[mid] < target)
            {
                l = mid + 1;
            }
            if (A[mid] == target)
            {
                ansr = mid;
                l = mid + 1;
            }
        }
        ans.push_back(ansl);
        ans.push_back(ansr);
        return ans;
    }
};

void printVector(vector<int>& pt)
{
    cout << "[";
    for (int j = 0; j < pt.size(); j++)
    {
        cout << pt[j] << " ";
    }
    cout << "]" << endl;
}

int main()
{  
    Solution s;

    int arr1[] = { 5, 7, 7, 8, 8, 10 };
    vector<int> A1(begin(arr1), end(arr1));

    vector<int> v;
    v = s.searchRange(A1, 8);
    printVector(v);
}
