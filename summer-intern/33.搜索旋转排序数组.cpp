/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-10-13 15:00:01
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-10-13 15:24:53
 * @FilePath: /Code/leetcode/33.搜索旋转排序数组.cpp
 */
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l=0,r = nums.size()-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;

            if(nums[mid]==target)
            {
                return mid;
            }
            else
            {
                if(nums[l]<=nums[mid])
                {
                    if(nums[mid]>target&&nums[l]<=target)
                    {
                        r= mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                else if (nums[mid]<=nums[r])
                {
                    if(nums[mid]<target&&nums[r]>=target)
                    {
                        l= mid + 1;
                    }
                    else
                    {
                        r= mid-1;
                    }
                }
            }
        }
        return -1;

    }
};
// @lc code=end

