/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-20 23:13:36
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-20 23:22:41
 * @FilePath: /leetcode/279.完全平方数.cpp
 */
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {

        vector<int> dp(n+1,INT_MAX);

        dp[0] = 0;
        
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j*j<=i;++j)
            {
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        
        return dp[n];


    }
};
// @lc code=end

