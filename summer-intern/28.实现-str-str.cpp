/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-03-13 21:07:27
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-14 09:33:17
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
//KMP
    void getNext(int* next, const string& s)
    {
        int j=-1;
        next[0]=j;
        for(int i=1;i<s.length();++i)
        {
            while(j>=0&&s[i]!=s[j+1])
            {
                j=next[j];
            }
            if(s[i]==s[j+1])
            {
                j++;
            }
            next[i]=j;
        }
    }
    int strStr(string haystack, string needle)
    {
//暴力
        // int n = haystack.size(), m = needle.size();
        // for (int i = 0; i + m <= n; i++)
        // {
        //     bool flag = true;
        //     for (int j = 0; j < m; j++)
        //     {
        //         if (haystack[i + j] != needle[j])
        //         {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if (flag)
        //     {
        //         return i;
        //     }
        // }
        // return -1;
//KMP
        if(needle.length()==0)
        {
            return 0;
        }
        int next[needle.length()];
        getNext(next, needle);
        int j=-1;
        for(int i=0;i<haystack.length();++i)
        {
            while(j>=0&&haystack[i]!=needle[j+1])
            {
                j=next[j];
            }
            if(haystack[i]==needle[j+1])
            {
                j++;
            }
            if(j==needle.length()-1)
            {
                return i-needle.length()+1;
            }
        }
        return -1;
    }
};
// @lc code=end
