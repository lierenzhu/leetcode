/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-05 23:35:24
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-06 01:13:13
 * @FilePath: \leetcode-autumn\33.搜索旋转排序数组.cpp
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
        int len=nums.size();
        if(len==0)
        {
            return -1;
        }
        if(len==1)
        {
            return nums[0]==target?0:-1;
        }
        int left=0,right=len-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[0]<=nums[mid])
            {
                if(nums[0]<=target&&target<nums[mid])
                {
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(nums[mid]<target&&target<=nums[len-1]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return -1;

    }
};
// @lc code=end

