/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-21 17:00:31
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-21 17:25:13
 * @FilePath: /leetcode/300.最长递增子序列.cpp
 */
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int m=nums.size();
        vector<int> dp(m,1);
        int maxSeq=0;

        for(int i=0;i<m;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }

            if(dp[i]>maxSeq)
            {
                maxSeq=dp[i];
            }
        }
        
        return maxSeq;

    }
};
// @lc code=end

