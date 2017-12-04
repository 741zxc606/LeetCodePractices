/*
 * 123.Best Time to Buy and Sell Stock III
 * Say you have ans array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profix.You may complete at most two transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie,you must sell the stock before you buy again).
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty()) return 0;
        int low = prices.front(), high = prices.back(), ret = 0;
        vector<int>history;
        history.reserve(prices.size());

        for (auto today : prices)
        {
            low = min(low, today);
            ret = max(ret, today - low);
            history.push_back(ret);
        }

        for (auto today = prices.crbegin(), past = history.crbegin(); today != prices.crend(); ++today, ++past)
        {
            high = max(high, *today);
            ret = max(ret, *past + high - *today);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> prices = { 4,2,3,1,9,3,7,6,8,3 };
    std::cout << s.maxProfit(prices) << std::endl;
    return 0;
}
