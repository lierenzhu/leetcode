/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-19 22:45:03
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-19 23:26:36
 * @FilePath: /leetcode/221.最大正方形.cpp
 */
/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int m=matrix.size(),n = matrix[0].size(), max_area=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                    max_area=max(max_area,dp[i][j]);
                }
            }
        }

        return max_area*max_area;

    }
};
// @lc code=end

