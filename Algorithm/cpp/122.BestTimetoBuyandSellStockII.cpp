/*
 * 122.Best Time to Buy and Sell Stock II
 * So you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit.You may complete as many transactions as you like
 * (ie,buy one and sell one share of the stock multiple times).However,you may not engage in multiple
 * transactions at the same time (ie,you must sell stock before you buy again).
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        for (auto i = prices.begin(); i != prices.end(); ++i)
            if (i + 1 != prices.end() && *(i + 1) > *i)profit += *(i + 1) - *i;
        return profit;
    }
};

int main()
{
    vector<int> prices = {4,2,3,1,9,3,7,6,8,3};
    Solution s;
    std::cout << s.maxProfit(prices) << std::endl;
}
