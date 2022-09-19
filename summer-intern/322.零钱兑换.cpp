/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-02-25 15:23:11
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-19 10:10:45
 * @FilePath: /leetcode/summer-intern/322.零钱兑换.cpp
 */
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        // int n = coins.size();
        // int minNum = INT_MAX;
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));

        // for (int i = 0; i < n + 1; i++)
        // {
        //     dp[i][0] = 0;
        // }

        // for (int i = 1; i <= n; ++i)
        // {
        //     int cur = coins[i - 1];
        //     for (int j = 1; j <= amount; ++j)
        //     {
        //         if (cur <= j)
        //         {
        //             dp[i][j] = min(dp[i - 1][j], dp[i][j - cur] + 1);
        //         }
        //         else
        //         {
        //             dp[i][j] = dp[i - 1][j];
        //         }
        //         if (dp[i][j] < minNum)
        //         {
        //             minNum = dp[i][j];
        //         }
        //     }
        // }

        // return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];

        //空间优化版本
        vector<int> dp(amount+1,amount+1);

        dp[0]=0;

        for(int coin:coins)
        {
            for(int j=1;j<=amount;++j)
            {
                if(coin<=j)
                {
                    dp[j]=min(dp[j],dp[j-coin]+1);
                }
            }
        }

        return dp[amount]== amount+1?-1:dp[amount];
    }
};
// @lc code=end
