/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-09 14:48:51
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-09 15:12:54
 * @FilePath: /leetcode/303.区域和检索-数组不可变.cpp
 */
/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
//菜鸡的写法
    // NumArray(vector<int>& nums) {

    //     pre_sum.push_back(nums[0]);
    //     for(int i = 1; i < nums.size();++i)
    //     {
    //         pre_sum.push_back(pre_sum[i-1]+nums[i]);
    //     }

    // }
    
    // int sumRange(int left, int right) {
    //     if(left==0)
    //     {
    //         return pre_sum[right];
    //     }
    //     else
    //     {
    //         return pre_sum[right]-pre_sum[left-1];
    //     }

    // }
    // vector<int> pre_sum;
//大佬的写法
    vector<int> psum;
    NumArray(vector<int> &nums) : psum(nums.size()+1,0){

        partial_sum(nums.begin(),nums.end(),psum.begin()+1);

    }

    int sumRange(int left, int right) {

        return psum[right+1]-psum[left];

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

