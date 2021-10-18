/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-10-18 16:14:53
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-10-18 16:42:11
 * @FilePath: /Code/leetcode/153.寻找旋转排序数组中的最小值.cpp
 */
/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]<nums[r])
            {
                r=mid;
            }
            else
            {
                l=mid + 1;
            }
        }
        return nums[l];

    }
};
// @lc code=end

