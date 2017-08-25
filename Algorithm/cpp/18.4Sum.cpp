/*
 * 18. 4Sum
 * Given an array S of n integers,are there elements a,b,c,and d in S such that a+b+c+d=target?
 * Find all unique quadruplets in the array which gives the sum of target.
 * Note:The solution set must not contain duplicate quadruplets.
 * For example,given array S=[1,0,-1,0,-2,2],and target =0.
 * A solution set is:
 * [
 *  [-1,0,0,1],
 *  [-2,-1,1,2],
 *  [-2,0,0,2]
 * ]
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int> num, int target);

vector<vector<int>> fourSum(vector<int> &num,int target)
{
	vector<vector<int>> result;
	if (num.size() < 4) return result;
	sort(num.begin(),num.end());

	for (int i = 0; i < num.size() - 3; i++)
	{
		//skip the duplication
		if (i > 0 && num[i - 1] == num[i]) continue;
		vector<int> n(num.begin() + i + 1, num.end());
		vector<vector<int>> ret = threeSum(n, target - num[i]);
		for (int j = 0; j < ret.size(); j++)
		{
			ret[j].insert(ret[j].begin(), num[i]);
			result.push_back(ret[j]);
		}
	}
	return result;
}

vector<vector<int>> threeSum(vector<int> num, int target)
{
	vector<vector<int>> result;

	//sort the array,this is the key
	sort(num.begin(), num.end());

	int n = num.size();

	for (int i = 0; i < n - 2; i++)
	{
		//skip the duplication
		if (i > 0 && num[i - 1] == num[i])continue;
		int a = num[i];
		int low = i + 1;
		int high = n - 1;
		while (low < high)
		{
			int b = num[low];
			int c = num[high];
			if (a + b + c == target)
			{
				//got the solution
				vector<int> v;
				v.push_back(a);
				v.push_back(b);
				v.push_back(c);
				result.push_back(v);
				//continue search for all triplet combinations summing to zero.
				//skip the duplication
				while (low < n && num[low] == num[low + 1])low++;
				while (high > 0 && num[high] == num[high - 1]) high--;
				low++;
				high--;
			}
			else if (a + b + c > target)
			{
				//skip the duplication
				while (high > 0 && num[high] == num[high - 1]) high--;
				high--;
			}
			else
			{
				//skip the duplication
				while (low<n && num[low] == num[low + 1]) low++;
				low++;
			}
		}
	}
	return result;
}

void printMatrix(vector<vector<int>>&matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		printf("{");
		for (int j = 0; j < matrix[i].size(); j++)
		{
			printf("%3d", matrix[i][j]);
		}
		printf("}");
	}
	cout << endl;
}

int main()
{
	int a[] = { 1,0,-1,0,-2,2 };
	vector<int> n(a,a+6);
	int t = 0;
	vector<vector<int>> v = fourSum(n, t);
	printMatrix(v);

	n.clear();
	int b[] = {-1,-5,-5,-3,2,5,0,4};
	n.insert(n.begin(), b, b + 8);
	t = -7;
	v = fourSum(n, t);
	printMatrix(v);

	return 0;
}
