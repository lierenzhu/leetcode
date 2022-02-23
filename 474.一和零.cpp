/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-23 17:30:33
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-23 18:46:43
 * @FilePath: /leetcode/474.一和零.cpp
 */
/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        // //三维数组解法
        // int size = strs.size();
        // vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));

        // for(int i=1;i<=size;++i)
        // {
        //     int num0=count(strs[i-1].begin(),strs[i-1].end(),'0');
        //     int num1=count(strs[i-1].begin(),strs[i-1].end(),'1');
        //     for(int j=0;j<=m;++j)
        //     {
        //         for(int k=0;k<=n;++k)
        //         {
        //             if(num0<=j&&num1<=k)
        //             {
        //                 dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-num0][k-num1]+1);
        //             }
        //             else
        //             {
        //                 dp[i][j][k]=dp[i-1][j][k];
        //             }
        //         }
        //     }
        // }

        // return dp[size][m][n];

        // 将三维优化到二维
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(string str:strs)
        {
            int num0=count(str.begin(),str.end(),'0');
            int num1=count(str.begin(),str.end(),'1');

            for(int i=m;i>=num0;--i)
            {
                for(int j=n;j>=num1;--j)
                {
                    dp[i][j]=max(dp[i][j],dp[i-num0][j-num1]+1);
                }
            }
        }

        return dp[m][n];

    }
};
// @lc code=end

