/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-07 10:36:11
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-08 09:41:10
 * @FilePath: /leetcode/leetcode-autumn/5.最长回文子串.cpp
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<1)
        {
            return "";
        }
        int start=0,end=0;
        for(int i=0;i<s.size();++i)
        {
            int len1=expandAroundCenter(s,i,i);
            int len2=expandAroundCenter(s,i,i+1);
            int maxLen=max(len1,len2);
            if(maxLen>end-start){
                start=i-(maxLen-1)/2;
                end=i+maxLen/2;
            }
        }
        return s.substr(start,end-start+1);

    }
private:
    int expandAroundCenter(string s,int left,int right){
        int l=left,r=right;
        while(l>=0&&r<s.size()&&s[l]==s[r])
        {
            --l;
            ++r;
        }
        return r-l-1;
    }
};
// @lc code=end

