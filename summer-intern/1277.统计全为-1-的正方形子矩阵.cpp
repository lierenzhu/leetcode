/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-19 23:40:24
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-19 23:50:44
 * @FilePath: /leetcode/1277.统计全为-1-的正方形子矩阵.cpp
 */
/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        if(matrix.empty()||matrix[0].empty())
        {
            return 0;
        }

        int m=matrix.size(),n = matrix[0].size(),result=0;
        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]==1)
                {
                    if(i==0||j==0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    }
                }

                result+=dp[i][j];
            }
        }

        return result;
    }
};
// @lc code=end

