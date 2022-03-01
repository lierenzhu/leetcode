/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-01 19:32:45
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-01 20:07:31
 * @FilePath: /leetcode/309.最佳买卖股票时机含冷冻期.cpp
 */
/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int days = prices.size();

        // //三种状态：
        // //持有股票
        // //不持有股票但处于冷冻期
        // //不持有股票且不在冷冻期
        // vector<vector<int>> dp(days,vector<int>(3,0));

        // dp[0][0]=-prices[0];

        // for(int i = 1; i < days;++i)
        // {
        //     //持有股票可能是当天买入或持续持有，两者取收益最大
        //     dp[i][0]=max(dp[i-1][2]-prices[i],dp[i-1][0]);
        //     //不持股但在冷冻期只可能是上一天卖出了股票
        //     dp[i][1]=dp[i-1][0]+prices[i];
        //     //不持股且不在冷冻期可能是前一天处于冷冻期或更早，两种情况取收益最大
        //     dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
        // }

        // return max(dp[days-1][1],dp[days-1][2]);

        //优化空间：去掉天数维度

        int dp0=-prices[0],dp1=0,dp2=0;
        
        for(int i=0;i<days;++i)
        {
            int new0=max(dp2-prices[i],dp0);
            int new1=dp0+prices[i];
            int new2=max(dp1,dp2);
            dp0=new0;
            dp1=new1;
            dp2=new2;
        }

        return max(dp1,dp2);
    }
};
// @lc code=end

