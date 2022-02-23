/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-23 16:24:38
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-23 17:20:57
 * @FilePath: /leetcode/416.分割等和子集.cpp
 */
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)
        {
            return false;
        }
        
        int target=sum/2,n=nums.size();

        // vector<vector<bool>> dp(n+1,vector<bool> (target+1,false));
        vector<bool> dp(target+1,false);

        // dp[0][0]=true;
        dp[0]=true;

        for(int i=1;i<=n;++i)
        {
            for(int j=target;j>=nums[i-1];--j)
            {
                    dp[j]=dp[j]||dp[j-nums[i-1]];
            }
        }

        return dp[target];

    }
};
// @lc code=end

