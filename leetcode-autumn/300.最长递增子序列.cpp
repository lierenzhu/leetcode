/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-08 20:22:28
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-08 20:48:12
 * @FilePath: /leetcode/leetcode-autumn/300.最长递增子序列.cpp
 */
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        int maxLen=0;
        vector<int> dp(len,1);
        for(int i=0;i<len;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxLen=max(maxLen,dp[i]);
        }
        return maxLen;
    }
};
// @lc code=end

