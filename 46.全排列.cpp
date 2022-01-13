/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-01-13 23:42:30
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-01-13 23:54:03
 * @FilePath: /leetcode/46.全排列.cpp
 */
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;
        backtrace(nums,0,result);
        return result;

    }

    void backtrace(vector<int> &nums, int level, vector<vector<int> > &result) 
    {
        if(level==nums.size()-1)
        {
            result.push_back(nums);
            return;
        }

        for(int i=level; i<nums.size();++i)
        {
            swap(nums[i],nums[level]);
            backtrace(nums,level+1,result);
            swap(nums[i],nums[level]);
        }
    }
};
// @lc code=end

