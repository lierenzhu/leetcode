/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-11-18 20:49:08
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-11-18 21:56:09
 * @FilePath: /leetcode/540.有序数组中的单一元素.cpp
 */
/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
// class Solution
// {
// public:
//     int singleNonDuplicate(vector<int> &nums)
//     {
//         int l = 0, r = nums.size() - 1;
//         while (l < r)
//         {
//             int mid = l + (r - l) / 2;
//             bool halvesAreEven = (r - mid) % 2 == 0;
//             if (nums[mid] == nums[mid + 1])
//             {
//                 if (halvesAreEven)
//                 {
//                     l = mid + 2;
//                 }
//                 else
//                 {
//                     r = mid - 1;
//                 }
//             }
//             else if (nums[mid - 1] == nums[mid])
//             {
//                 if (halvesAreEven)
//                 {
//                     r=mid -2;
//                 }
//                 else
//                 {
//                     l = mid + 1;
//                 }
//             }
//             else
//             {
//                 return nums[mid];
//             }
//         }
//         return nums[l];
//     }
// };

//solution2
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size()-1;
        while(l<r)
        {
            int mid = l + (r - l) / 2;
            if(mid%2==1)
            {
                mid--;
            }
            if(nums[mid]==nums[mid+1])
            {
                l=mid+2;
            }
            else
            {
                r=mid;
            }
        }
        return nums[l];
    }
};
// @lc code=end
