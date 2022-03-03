/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-03 09:29:20
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-03 09:58:48
 * @FilePath: /leetcode/583.两个字符串的删除操作.cpp
 */
/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        // 根据最长子序列推出删除次数
        // for(int i=1;i<=m;++i)
        // {
        //     for(int j=1;j<=n;++j)
        //     {
        //         if(word1[i-1]==word2[j-1])
        //         {
        //             dp[i][j]=dp[i-1][j-1]+1;
        //         }
        //         else
        //         {
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }

        //dp数组直接存储删除次数
        for(int i=1;i<=m;++i)
        {
            dp[i][0]=i;
        }
        for(int j=1;j<=n;++j)
        {
            dp[0][j]=j;
        }
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        }

        for(vector<int> i:dp)
        {
            for(int j:i)
            {
                cout << j << " ";
            }
            cout << endl;
        }

        return dp[m][n];

        // return m+n-2*dp[m][n];

    }
};
// @lc code=end

