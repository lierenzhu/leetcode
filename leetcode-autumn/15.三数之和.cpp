/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-09-03 17:06:24
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-03 18:05:47
 * @FilePath: /leetcode/leetcode-autumn/15.三数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i)
        {
            if(nums[i]>0){
                break;
            }
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int l = i+1, r = nums.size()-1;
            while (l < r)
            {
                int sum=nums[l]+nums[r]+nums[i];
                if (sum == 0)
                {
                    result.push_back(vector<int>{nums[l], nums[r], nums[i]});
                    while(l<r&&nums[r]==nums[--r]);
                    while(l<r&&nums[l]==nums[++l]);
                }
                else if (sum > 0)
                {
                    while(l<r&&nums[r]==nums[--r]);
                }
                else
                {
                    while(l<r&&nums[l]==nums[++l]);
                }
            }
        }
        return result;
    }
};
// @lc code=end
