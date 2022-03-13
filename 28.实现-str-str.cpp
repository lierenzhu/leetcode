/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-03-13 21:07:27
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-13 22:06:39
 * @FilePath: /leetcode/28.实现-str-str.cpp
 */
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
//暴力
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
