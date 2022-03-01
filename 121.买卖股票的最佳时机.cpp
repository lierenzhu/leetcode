/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-01 09:08:52
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-01 09:28:28
 * @FilePath: /leetcode/121.买卖股票的最佳时机.cpp
 */
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int m=prices.size();
        int buy=INT_MAX,sell=0;

        for(int i=0; i<m; i++)
        {
            buy=min(buy, prices[i]);
            sell=max(sell, prices[i]-buy);
        }

        return sell;

        //暴力解法会超时
        // int maxMoney = 0;
        // for(int i=0;i<m;++i)
        // {
        //     for(int j=i+1;j<m;++j)
        //     {
        //         if(prices[j]-prices[i]>maxMoney)
        //         {
        //             maxMoney = prices[j]-prices[i];
        //         }
        //     }
        // }

        // return maxMoney;

    }
};
// @lc code=end

