/*
 * 11.Container With Most Water
 * Given n non-negatice integers a1,a2,...,an,where each represents a point at coordinate(i,ai).n vertical inles are drawn such that the
 * two endpoints of line i is at (i,ai) and (i,0).Find two lines,which together with x-axis forms a container,such that the container contains 
 * the most water.
 * Note:You may not slant the container and n is at least 2.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution 
{
public:
	int maxArea(vector<int>& height)
	{
		int i = 0, j = height.size() - 1, max_area = 0;
		while (i < j)
		{
			max_area = max(max_area, min(height[i], height[j])*(j - i));
			if (height[i] > height[j])
			{
				--j;
			}
			else if (height[i] < height[j])
			{
				++i;
			}
			else
			{
				++i, --j;
			}
		}
		return max_area;
	}
};

int main()
{  

	int height[] = { 1,2,3,4,3,2,1,5 };
	vector<int> H(begin(height),end(height));
	int MaxArea = solution().maxArea(H);
	cout << MaxArea << endl;
	return 0;
}
