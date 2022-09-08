/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-08 10:45:28
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-08 11:06:38
 * @FilePath: /leetcode/leetcode-autumn/46.全排列.cpp
 */
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backTrace(nums,0,result);
        return result;

    }
    void backTrace(vector<int> &nums,int depth,vector<vector<int>> &result){
        if(depth==nums.size()-1)
        {
            result.push_back(nums);
            return;
        }

        for(int i=depth;i<nums.size();++i)
        {
            swap(nums[i],nums[depth]);
            backTrace(nums,depth+1,result);
            swap(nums[i],nums[depth]);
        }
    }
};
// @lc code=end

