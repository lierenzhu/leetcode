/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-10 10:39:31
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-10 11:11:20
 * @FilePath: /leetcode/560.和为-k-的子数组.cpp
 */
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

//非常意料之中的超时了
        // vector<int> psum(nums.size()+1,0);
        // int ans=0;
        // partial_sum(nums.begin(),nums.end(),psum.begin()+1);

        // unordered_map<int,int> sum_count;

        // for(int i=1; i<=nums.size();++i)
        // {
        //     for(int j=i-1;j>=0;--j)
        //     {
        //         if(psum[i]-psum[j]==k)
        //         {
        //             ++ans;
        //         }
        //     }
        // }
        // return ans;


//正经人谁能想到这么做
    int ans=0,psum=0;
    unordered_map<int,int> hash;
    hash[0]=1;

    for(int num:nums)
    {
        psum+=num;
        ans+=hash[psum-k];
        ++hash[psum];
    }
    
    return ans;
    }
};
// @lc code=end

