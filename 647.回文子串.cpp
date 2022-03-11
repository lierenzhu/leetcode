/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-11 16:32:00
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-11 17:25:05
 * @FilePath: /leetcode/647.回文子串.cpp
 */
/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:

    int countSubstrings(string s) {
        int count = 0;
        int s_size=s.length();
        for(int i=0; i<s_size;++i)
        {
            count+=extendSubstring(s,i,i);
            count+=extendSubstring(s,i,i+1);
        }

        return count;
    }

    int extendSubstring(string s,int l,int r)
    {
        int count=0;
        while(l>=0&&r<s.length()&&s[l]==s[r])
        {
            ++count;
            --l;
            ++r;
        }

        return count;
    }
        
//又是十分理所应当的超时了
    // int countSubstrings(string s) {
    //     int count=0;
    //     for(int i=0; i<s.length(); ++i)
    //     {
    //         for(int j=0;j<s.length()-i; ++j)
    //         {
    //             if(isSunstring(s.substr(i,j+1)))
    //             {
    //                 cout<< s.substr(i,j+1)<<endl;
    //                 count++;
    //             }
    //         }
    //     }

    //     return count;
    // }

    // bool isSunstring(string s)
    // {
    //     int mid_size=s.length()/2;
    //     for(int i=0;i<mid_size;++i)
    //     {
    //         if(s[i]!=s[s.length()-i-1])
    //         {
    //             return false;
    //         }
    //     }

    //     return true;
    // }
};
// @lc code=end

