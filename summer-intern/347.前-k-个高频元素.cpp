/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-12-23 21:05:17
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-12-23 21:12:47
 * @FilePath: /leetcode/347.前-k-个高频元素.cpp
 */
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int max_count = 0;
        for(int & num : nums)
        {
            max_count=max(max_count,++count[num]);
        }

        vector<vector<int> > buckets(max_count+1);

        for(const auto & p : count)
        {
            buckets[p.second].push_back(p.first);
        }

        vector<int> result;

        for(int i=max_count;i>=0&&result.size()<k;i--)
        {
            for(const int & num : buckets[i])
            {
                result.push_back(num);
                if(result.size()==k)
                {
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

