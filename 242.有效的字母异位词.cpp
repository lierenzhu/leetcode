/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-11 09:25:28
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-11 09:43:29
 * @FilePath: /leetcode/242.有效的字母异位词.cpp
 */
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> s_hash,t_hash;
        for(char c:s)
        {
            s_hash[c]++;
        }
        for(char c:t)
        {
            t_hash[c]++;
        }

        if(s_hash.size()!=t_hash.size())
        {
            return false;
        }
        for(map<char,int>::iterator its=s_hash.begin(),itt=t_hash.begin();its!=s_hash.end()&&itt!=t_hash.end();its++,itt++)
        {
            if(its->first!=itt->first||its->second!=itt->second)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

