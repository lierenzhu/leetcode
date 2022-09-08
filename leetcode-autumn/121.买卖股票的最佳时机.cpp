/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int days=prices.size();
        // int minPrice=prices[0];
        // vector<int> dp(days,0);

        // for(int i=1;i<days;++i)
        // {
        //     dp[i]=max(dp[i-1],prices[i]-minPrice);
        //     minPrice=min(prices[i],minPrice);
        // }

        // return dp[days-1];
        int minPrice=INT_MAX;
        int maxProfit=0;

        for(int price:prices)
        {
            minPrice=min(minPrice,price);
            maxProfit=max(maxProfit,price-minPrice);
        }

        return maxProfit;

    }
};
// @lc code=end

