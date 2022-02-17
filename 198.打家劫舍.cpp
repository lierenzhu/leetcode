/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-18 00:05:41
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-18 00:17:40
 * @FilePath: /leetcode/198.打家劫舍.cpp
 */
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) 
        {
            return 0;
        }

        int n=nums.size();
        vector<int> dp(n+1,0);

        dp[1]=nums[0];

        for(int i=2;i<=n;++i)
        {
            dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
        }

        return dp[n];

    }
};
// @lc code=end

