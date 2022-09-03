/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-22 15:10:08
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-22 15:33:08
 * @FilePath: /leetcode/1143.最长公共子序列.cpp
 */
/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m=text1.length(),n=text2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        // for(vector<int> i:dp)
        // {
        //     for(int j:i)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }

        return dp[m][n];

    }
};
// @lc code=end

