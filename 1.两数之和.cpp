/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-08 14:38:26
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-08 14:49:31
 * @FilePath: /leetcode/1.两数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> hash;
        vector<int> ans;

        for(int i=0; i<nums.size();++i)
        {
            int num=nums[i];
            auto pos=hash.find(target-num);
            if(pos!=hash.end())
            {
                ans.push_back(i);
                ans.push_back(pos->second);
                break;
            }
            else
            {
                hash[num]=i;
            }
        }
        return ans;
    }
};
// @lc code=end

