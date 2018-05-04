/*
 * 164.Maximum Gap
 * Given an unsorted array,find the maximum difference between the successive elements in its sorted form.
 * Return 0 if the array contains less than 2 elements.
 * Example 1:
 *  Input:[3,6,9,1]
 *  Output:3
 *  Explanation:The sorted form of the array is [1,3,6,9],either 3,6 or 6,9 has the maximum difference 3.
 * Example 2:
 *  Input:[10]
 *  Output:0
 *  Explanation:The array contains less than 2 elements,therefore return 0.
 * Note:
 *  1.You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 *  2.Try to solve it in linear time/space.
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>&nums)
	{
        if (nums.size() < 2) return 0;

        //find the max and min element
        int min = nums[0], max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            min = min > nums[i] ? nums[i] : min;
            max = max < nums[i] ? nums[i] : max;
        }

        //divide the interval [min,max] into n "buckets" of equal size=(max-min)/n
        int bucket_size = (max - min) / nums.size() + 1;

        //for each of the remaining n-2 numbers,determine in which bucket it falls.
        //the number nums[i] belongs to the kth bucket B[k] if and only if (nums[i]-min)/m=k-1;

        vector<vector<int>>buckets((max - min) / bucket_size + 1);
        //for each bucket B[k],compute its max & min among the numbes which falls in B[k].
        //it the bucket is empty,remain it nothing.
        //it the bucket has one number,make this number as both max & min
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = (nums[i] - min) / bucket_size;
            if (buckets[idx].empty())
            {
                buckets[idx].push_back(nums[i]);
                buckets[idx].push_back(nums[i]);
            }
            else
            {
                buckets[idx][0] = buckets[idx][0] > nums[i] ? nums[i] : buckets[idx][0];
                buckets[idx][1] = buckets[idx][1] < nums[i] ? nums[i] : buckets[idx][1];
            }
        }

        //caculate the max gap
        int maxGap = 0;
        int prev = 0;
        for (int i = 1; i < buckets.size(); i++)
        {
            if (buckets[i].empty()) continue;
            int gap = buckets[i][0] - buckets[prev][1];
            maxGap = maxGap > gap ? maxGap : gap;
            prev = i;
        }
        return maxGap;
	}
};

int main()
{
    Solution s;
    int a[] = { 3,6,9,1 };
    vector<int>nums(a, a + sizeof(a) / sizeof(a[0]));
    std::cout << s.maximumGap(nums) << std::endl;
    return 0;
}
