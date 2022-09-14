/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-13 10:39:24
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-13 11:05:59
 * @FilePath: /leetcode/leetcode-autumn/31.下一个排列.cpp
 */
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        int i=len-2,j=len-1;
        int k=len-1;
        while(i>=0&&nums[i]>=nums[j])
        {
            --i;
            --j;
        }
        if(i>=0)
        {
            while(nums[k]<=nums[i])
            {
                --k;
            }
            swap(nums[i],nums[k]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
// @lc code=end

