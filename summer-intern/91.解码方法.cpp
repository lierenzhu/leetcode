/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-20 23:34:46
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-21 00:16:32
 * @FilePath: /leetcode/91.解码方法.cpp
 */
/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {

        int m=s.length();
        if(m==0)
        {
            return 0;
        }

        vector<int> dp(m+1,1);
        int prev=s[0]-'0';
        if(!prev)
        {
            return 0;
        }
        if(m==1)
        {
            return 1;
        }

        for(int i=2;i<=m; ++i)
        {
            int cur=s[i-1]-'0';
            if((prev==0||prev>2)&&cur==0)
            {
                return 0;
            }
            if(prev==1||prev==2&&cur<=6)
            {
                if(cur)
                {
                    dp[i]=dp[i-2]+dp[i-1];
                }
                else
                {
                    dp[i]=dp[i-2];
                }
            }
            else
            {
                dp[i]=dp[i-1];
            }

            prev=cur;
        }

        return dp[m];

    }
};
// @lc code=end

