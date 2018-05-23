/*
 * 162.Find Peak Element
 * A peack element is an element that is greater than its neighbors.
 * Given an input array nums, where nums[i] != nums[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that nums[-1] = nums[n] = -∞.
 * Example 1:
 *      Input: nums = [1,2,3,1]
 *      Output: 2
 *      ExplanationL: 3 is a peak element and your function should return the index number 2.
 * Example 2:
 *      Input: nums = [1,2,1,3,5,6,4]
 *      Output: 1 or 5
 *      Explanation: Your function can return either index number 1 where the peak element is 2,
 *                   or index number 5 where the peak element is 6.
 * Note:
 * Your solution should be in logarithmic complexity.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Binary Search.
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        int mid = 0, v1, v2;

        while (low < high)
        {
            //Find the index of middle element
            mid = low + (high - low) / 2;

            //Compare middle element with its neighbors(if neghbors exists)
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1]))
            {
                return mid;
            }

            //If middle element is not peak and tis left neighbor is greater than it
            //Then left half must have a peak element
            if (mid > 0 && nums[mid - 1] > nums[mid])
            {
                high = mid - 1;
                //If middle element is not peak and its right neghbor is greater than it
                //Then right half must have a peak element
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

void printVector(vector<int>&n)
{
    cout << "[";
    int i;
    for (i = 0; i < n.size(); i++)
    {
        cout << n[i] << (i == n.size() - 1 ? "]" : ",");
    }
    cout << endl;
}

void test(int a[], int n)
{
    Solution s;
    vector<int> v(a, a + n);
    cout << "Peak Index =" << s.findPeakElement(v) << "\t";
    printVector(v);
}

#define TEST(a) test(a,sizeof(a)/sizeof(a[0]))

int main(int argc,char**argv)
{
    int n0[] = { 1 };
    TEST(n0);

    int n1[] = { 1,2,3,1 };
    TEST(n1);

    int n2[] = { 1,2,1,3,5,6,4 };
    TEST(n2);
}
