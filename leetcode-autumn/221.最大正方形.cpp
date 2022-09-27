/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-27 10:10:41
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-27 10:36:41
 * @FilePath: /leetcode/leetcode-autumn/221.最大正方形.cpp
 */
/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int result=0;
        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]=='1')
                {
                    if(i==0||j==0)
                    {
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                    }
                    result=max(result,dp[i][j]);
                }
            }
        }

        return result*result;

    }
};
// @lc code=end

