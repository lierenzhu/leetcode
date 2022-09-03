/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-01-04 20:47:23
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-01-04 21:17:25
 * @FilePath: /leetcode/451.根据字符出现频率排序.cpp
 */
/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> counts;
        int max_count=0;
        for(char c:s)
        {
            max_count=max(max_count,++counts[c]);
        }
        vector<vector<char> > buckets(max_count+1);
        for(auto p:counts)
        {
            buckets[p.second].push_back(p.first);
        }

        string result;
        for(int i=max_count;i>=0;--i)
        {
            for(char c:buckets[i])
            {
                result.append(i,c);
            }
        }
    return result;
    }
};
// @lc code=end

