/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-28 20:18:21
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-28 21:26:30
 * @FilePath: /leetcode/10.正则表达式匹配.cpp
 */
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

@lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {

        int m=s.length(),n=p.length();
        vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));

        dp[0][0]=true;

        //s串为空时，p串在a*b*c*这类情况下可以匹配上
        for(int i=1;i<n+1;++i)
        {
            if(p[i-1]=='*')
            {
                dp[0][i]=dp[0][i-2];
            }
        }

        for(int i=1;i<m+1;++i)
        {
            for(int j=1;j<n+1;++j)
            {
                //p[j-1]为'.'时可以匹配任意字符，状态与dp[i-1][j-1]相同
                if(p[j-1]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                //p[j-1]为普通字母时，只有上一状态与该字母都匹配才能为真
                else if(p[j-1]!='*')
                {
                    dp[i][j]=dp[i-1][j-1]&&s[i-1]==p[j-1];
                }
                //p[j-1]为'*'但前一字母不匹配时，“x*”这一组合匹配为0个字符
                //举例：s="abc" p="abcd*"
                //所以状态与p串删掉“d*”时的状态相同
                else if(p[j-2]!=s[i-1]&&p[j-2]!='.')
                {
                    dp[i][j]=dp[i][j-2];
                }
                //p[j-1]为'*'且前一字母匹配或为'.'时，分三种情况
                //s="abcccd",p="abc*d"，对应dp[i-1][j]，相当于从s串中去掉一个匹配字母，然后看是否匹配
                //s="abcd",p="abcd*"，对应dp[i][j-1]，'*'之前的串已经匹配
                //s="abcd",p="abcde*"，对应dp[i][j-2]，去掉"e*"之后是匹配的
                else
                {
                    dp[i][j]=dp[i-1][j]||dp[i][j-1]||dp[i][j-2];
                }
            }
        }

        return dp[m][n];

    }
};
// @lc code=end

