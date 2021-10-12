/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-10-12 15:02:22
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-10-12 17:29:46
 * @FilePath: /Code/leetcode/34.在排序数组中查找元素的第一个和最后一个位置.cpp
 */
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return vector<int>{-1, -1};
        }
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target);
        if (lower == nums.size() || nums[lower] != target)
        {
            return vector<int>{-1, -1};
        }
        return vector<int>{lower, upper};
    }

    int lower_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                while (mid >= 0 && nums[mid] == target)
                {
                    mid--;
                }
                mid++;
                break;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return mid;
    }

    int upper_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                while (mid <= nums.size() - 1 && nums[mid] == target)
                {
                    mid++;
                }
                mid--;
                break;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return mid;
    }
};
// @lc code=end
