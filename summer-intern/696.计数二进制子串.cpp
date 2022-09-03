/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-11 19:11:56
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-11 19:34:39
 * @FilePath: /leetcode/696.计数二进制子串.cpp
 */
/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {

        int pre=0,cur=1;
        int count = 0;
        for(int i=1;i<s.length();++i)
        {
            if(s[i]==s[i-1])
            {
                cur++;
            }
            else
            {
                pre=cur;
                cur=1;
            }
            if(pre>=cur)
            {
                count++;
            }
        }

        return count;

    }
};
// @lc code=end

