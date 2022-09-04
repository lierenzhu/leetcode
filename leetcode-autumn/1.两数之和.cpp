/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-04 20:48:41
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-04 21:16:03
 * @FilePath: \leetcode-autumn\1.两数之和.cpp
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
        map<int,int> hashMap;
        vector<int> result(2,-1);
        int len=nums.size();
        
        for(int i=0;i<len;++i)
        {
            if(hash.count(target-nums[i])>0)
            {
                result[0]=i;
                result[1]=hash[target-nums[i]];
                break;
            }
            hash[nums[i]]=i;
        }

        return result;
    }
};
// @lc code=end

