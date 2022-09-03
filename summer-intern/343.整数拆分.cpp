/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-03-02 17:04:29
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-02 22:52:58
 * @FilePath: /leetcode/343.整数拆分.cpp
 */
/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {

        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; ++i)
        {
            int cur_max = 0;
            for (int j = 1; j <= i / 2; ++j)
            {
                cur_max = max(j * (i - j), j * dp[i - j]);
                if (cur_max > dp[i])
                {
                    dp[i] = cur_max;
                }
            }
        }

        for (int i : dp)
        {
            cout << i << " ";
        }

        return dp[n];
    }
};
// @lc code=end
