/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-03 21:04:38
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-03 21:05:47
 * @FilePath: \leetcode-autumn\53.最大子数组和.cpp
 */
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        vector<int> dp(len,0);
        dp[0]=nums[0];
        int result=dp[0];
        for(int i=1;i<len;++i){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            result=max(result,dp[i]);
        }

        return result;
    }
};
// @lc code=end

