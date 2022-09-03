/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-01 10:59:02
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-01 16:55:47
 * @FilePath: /leetcode/188.买卖股票的最佳时机-iv.cpp
 */
/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int day=prices.size();
        vector<int> buy(k+1,INT_MIN);
        vector<int> sell(k+1,0);

        for(int i=0;i<day;++i)
        {
            for(int j=1;j<=k;++j)
            {
                buy[j] = max(buy[j],sell[j-1]-prices[i]);
                sell[j] = max(sell[j],buy[j]+prices[i]);
            }
        }

        return sell[k];

    }
};
// @lc code=end

