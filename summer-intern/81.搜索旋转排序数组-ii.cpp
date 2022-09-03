/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-10-13 10:10:03
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-10-13 11:31:19
 * @FilePath: /Code/leetcode/81.搜索旋转排序数组-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {

        int l = 0, r = nums.size()-1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else
            {
                if (nums[mid] == nums[l])
                {
                    l++;
                }
                else if (nums[mid] > nums[l]) //左边有序
                {
                    if(nums[mid]>target&&nums[l]<=target)
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                else if (nums[mid] <= nums[r])
                {
                    if(nums[mid]< target&&nums[r]>=target)
                    {
                        l= mid + 1;
                    }
                    else
                    {
                        r=mid-1;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
