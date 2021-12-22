/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-12-22 20:03:27
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-12-22 21:09:00
 * @FilePath: /leetcode/215.数组中的第k个最大元素.cpp
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution
{
public:
    int quickSelection(vector<int> &nums, int l, int r)
    {
        int i = l + 1, j = r;
        while (true)
        {
            while (i < r && nums[i] <= nums[l])
            {
                i++;
            }
            while (l < j && nums[j] >= nums[l])
            {
                j--;
            }
            if (i >= j)
            {
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int l = 0, r = nums.size() - 1, target = nums.size() - k;
        while (l < r)
        {
            int mid = quickSelection(nums, l, r);
            if (mid == target)
            {
                return nums[mid];
            }
            else if (mid < target)
            {
                l = mid + 1;
            }
            else if (mid > target)
            {
                r = mid - 1;
            }
        }
        return nums[l];
    }
};
// @lc code=end
