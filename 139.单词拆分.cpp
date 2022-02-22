/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-21 15:21:39
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-21 16:38:20
 * @FilePath: /leetcode/139.单词拆分.cpp
 */
/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int m=s.length();
        int dicSize=wordDict.size();
        vector<bool> dp(m+1,false);
        dp[0] = true;

        for(int i=1;i<=m;++i)
        {
            for(const string & word:wordDict)
            {
                int length=word.length();
                if(i>=length&&s.substr(i-length,length)==word)
                {
                    dp[i]=dp[i]||dp[i-length];
                }
            }
        }

        return dp[m];

    }
};
// @lc code=end

