/*
 * 135.Candy
 * There are N children standing in a line.Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 *		1.Each child must have at least one candy.
 *		2.Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings)
	{
		int size = ratings.size();
		if (size <= 1)
			return size;
		vector<int>num(size, 1);
		for (int i = 1; i < size; i++)
		{
			if (ratings[i] > ratings[i - 1])
				num[i] = num[i - 1] + 1;
		}
		for (int i = size - 1; i > 0; i--)
		{
			if (ratings[i - 1] > ratings[i])
				num[i - 1] = max(num[i] + 1, num[i - 1]);
		}
		int result = 0;
		for (int i = 0; i < size; i++)
		{
			result += num[i];
		}
		return result;
	}
};

void generateRatings(vector<int>&ratings, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		ratings.push_back(rand() % 10);
	}
}

void print(vector<int>&v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(int argc,char**argv)
{
	Solution s;

	int n = 10;
	if (argc > 1)
	{
		n = atoi(argv[1]);
	}

	vector<int> ratings;
	generateRatings(ratings, n);
	print(ratings);

	cout << "--------------------" << endl;
	int r[] = { 5,7,4,2,9,1,3,0,8,6 };
	vector<int>ra(r, r + sizeof(r) / sizeof(r[0]));
	print(ra);
	cout << s.candy(ra) << endl;
	return 0;
}
