/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-10-13 15:34:25
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-10-13 17:37:40
 * @FilePath: /Code/leetcode/154.寻找旋转排序数组中的最小值-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {

        int l=0,r = nums.size()-1;
        int min;
        if (nums.size()==1)
        {
            return nums[0];
        }
        while(l<=r)
        {
            int mid = l + (r - l) / 2;
            if(nums[l]==nums[mid])
            {
                l++;
            }
            else
            {
                if(nums[l]<nums[mid])
                {
                    min=nums[l];
                    l=mid+1;
                }
                else if(nums[mid]<nums[r])
                {
                    min=nums[mid];
                    r=mid-1;
                }
            }
        }
        return min;

    }
};
// @lc code=end

