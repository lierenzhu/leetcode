/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        for(int & num:nums)
        {
            int pos=abs(num)-1;
            if(nums[pos]>0)
            {
                nums[pos]= -nums[pos];
            }
        }

        vector<int> result;

        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>0)
            {
                result.push_back(i+1);
            }
        }

        return result;
    }
};
// @lc code=end

