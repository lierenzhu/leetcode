/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-08-23 16:56:19
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-08-24 10:00:46
 * @FilePath: /e:\code\Cpp\leetcodee:\code\Cpp\leetcode/763.划分字母区间.cpp
 */
/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        vector<int> result;
        for (int i = 0; i < 26;i++)
        {
            last[i] = s.find_last_of('a'+i);
        }
        int start=0,end=0;
        for(int i=0;i<s.size();i++)
        {
            end=max(end,last[s[i]-'a']);
            if(end==i)
            {
                result.push_back(end-start+1);
                start = end+1;
            }
        }
        return result;
    }
};
// @lc code=end

