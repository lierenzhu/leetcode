/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-28 11:07:53
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-28 15:27:28
 * @FilePath: /leetcode/650.只有两个键的键盘.cpp
 */
/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {

        vector<int> dp(n+1,0);
        
        for(int i=2;i<=n;++i)
        {
            dp[i]=i;    //长度为i的串需要的最大操作次数是i（1次拷贝，i-1次粘贴）
            for(int j=2;j*j<=i;++j)
            {
                if(i%j==0)
                {
                    /*
                    解释：
                    假设需要凑出6个A，6/2=3，即将两个一组的A复制2次
                    得到两个A的操作为dp[2]
                    随后将这两个A看作一组，得到六个A的操作与从1个A得到3个A的操作相同
                    从1个A到3个A的操作是dp[3]，所以2->6的操作也是dp[3]
                    于是有了dp[6]=dp[2]+dp[3]
                    所以有如下的状态转移方程
                    */
                    dp[i]=dp[j]+dp[i/j];
                    break;
                }
            }
        }

        for(int i:dp)
        {
            cout << i << " ";
        }

        return dp[n];

    }
};
// @lc code=end

