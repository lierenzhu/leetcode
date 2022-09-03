/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-10 22:28:18
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-10 22:51:29
 * @FilePath: /leetcode/697.数组的度.cpp
 */
/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> left_pos, right_pos, count;
        int degree = 0;
        int ans=nums.size();
        
        for(int i=0;i<nums.size();++i)
        {
            if(!left_pos.count(nums[i]))
            {
                left_pos[nums[i]] = i;
            }
            right_pos[nums[i]] = i;
            count[nums[i]]++;
            degree=max(degree,count[nums[i]]);
        }

        for(auto &kv:count)
        {
            if(kv.second==degree)
            {
                ans=min(ans,right_pos[kv.first]-left_pos[kv.first]+1);
            }
        }

        return ans;
        

    }
};
// @lc code=end

