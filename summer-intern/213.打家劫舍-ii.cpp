/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {

        int m=nums.size();

        if(m==1)
        {
            return nums[0];
        }

        vector<int> dp(m,0);
        int no_haed_max=0,no_tail_max=0;

        dp[1]=nums[1];
        for(int i=2;i<=m-1;++i)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        no_haed_max=dp[m-1];

        dp[1]=nums[0];
        for(int i=2;i<=m-1;++i)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        no_tail_max=dp[m-1];

        return max(no_haed_max,no_tail_max);

    }
};
// @lc code=end

