/*
 * 121.Best Time to Buy and Sell Stock
 * Say you have an array for which the ith element is the price of a stock on day i.
 * If you were only permitted to complete at most one transaction(ie,but one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 * Example 1:
    Input: [7,1,5,3,6,4]
    Output: 5

    max.difference= 6-1 = 5 (not 7-1 = 6, as sellinig price needs to be larger than buying price)
 * Example 2:
    Input: [7,6,4,3,1]
    Output: 0

    In this case, no transaction is done,i.e. max profit = 0.
 */

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfix(vector<int>& prices)
    {
        if (prices.empty()) return 0;
        int maxCur = 0, maxSoFar = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            maxCur = max(0, maxCur += prices[i] - prices[i - 1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }

    int maxProfit1(vector<int> &prices)
    {
        if (prices.empty()) return 0;
        int ret{ 0 }, low{ prices[0] };
        for (auto price : prices)
        {
            low = min(low, price);
            ret = max(ret, price - low);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> vec1{ 7,1,5,3,6,4 };
    vector<int> vec2{ 7,6,4,3,1 };

    cout << s.maxProfix(vec1) << endl;
    cout << s.maxProfix(vec2) << endl;

    return 0;
}

