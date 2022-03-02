/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-02 14:30:12
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-02 15:10:27
 * @FilePath: /leetcode/53.最大子数组和.cpp
 */
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int m=nums.size();
        if(m==1)
        {
            return nums[0];
        }
        // //此处dp为“以此位置结束的最大子数组和”
        // vector<int> dp(m+1,INT_MIN);
        int max_num=INT_MIN;

        int last_dp=0;
        for(int i=0;i<m;++i)
        {
            int dp=max(nums[i],last_dp+nums[i]);
            last_dp=dp;
            if(dp>max_num)
            {
                max_num=dp;
            }
        }

        // dp[1]=nums[0];
        // for(int i=2;i<=m;++i)
        // {
        //     dp[i]=max(nums[i-1],dp[i-1]+nums[i-1]);
        //     if(dp[i]>max_num)
        //     {
        //         max_num=dp[i];
        //     }
        // }

        return max_num;


    }
};
// @lc code=end

