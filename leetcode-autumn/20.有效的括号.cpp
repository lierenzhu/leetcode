/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-07 09:59:54
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-07 10:33:38
 * @FilePath: /leetcode/leetcode-autumn/20.有效的括号.cpp
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s)
        {
            if(c=='('||c=='['||c=='{')
            {
                st.push(c);
                continue;
            }
            if(c==')')
            {
                if(st.empty()||st.top()!='(')
                {
                    return false;
                }
                st.pop();
                continue;
            }
            if(c==']')
            {
                if(st.empty()||st.top()!='[')
                {
                    return false;
                }
                st.pop();
                continue;
            }
            if(c=='}')
            {
                if(st.empty()||st.top()!='{')
                {
                    return false;
                }
                st.pop();
                continue;
            }
        }
        return st.empty();

    }
};
// @lc code=end

