/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-08 14:50:35
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-08 15:12:27
 * @FilePath: /leetcode/128.最长连续序列.cpp
 */
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int ans=0;
        unordered_set<int> hash;

        for(int num:nums)
        {
            hash.insert(num);
        }

        while(!hash.empty())
        {
            int cur=*(hash.begin());
            hash.erase(cur);
            int prev=cur-1,next=cur+1;
            while(hash.count(prev))
            {
                hash.erase(prev--);
            }
            while(hash.count(next))
            {
                hash.erase(next++);
            }

            ans=max(ans,next-prev-1);
        }

        return ans;

    }
};
// @lc code=end

