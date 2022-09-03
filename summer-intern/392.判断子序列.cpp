/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-10-12 09:51:45
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-10-12 10:10:40
 * @FilePath: /Code/leetcode/392.判断子序列.cpp
 */
/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.size(), tLen = t.size();
        int i=0;
        for(char c:s)
        {
            while(i<tLen && t[i]!=c)
            {
                i++;
            }
            if(i>=tLen)
            {
                return false;
            }
            i++;
        }
        return true;

    }
};
// @lc code=end

