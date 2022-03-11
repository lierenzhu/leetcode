/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-11 09:50:45
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-11 10:26:31
 * @FilePath: /leetcode/205.同构字符串.cpp
 */
/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s2t;
        unordered_map<char,char> t2s;

        for(int i=0;i<s.length();++i)
        {
            if(!s2t.count(s[i]))
            {
                s2t[s[i]]=t[i];
            }
            if(!t2s.count(t[i]))
            {
                t2s[t[i]]=s[i];
            }

            if(t[i]!=s2t[s[i]]||s[i]!=t2s[t[i]])
            {
                return false;
            }
        }

        return true;

    }
};
// @lc code=end

