/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-06 14:59:16
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-06 15:48:57
 * @FilePath: /leetcode/20.有效的括号.cpp
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(int i=0; i<s.length(); ++i)
        {
            char c=s[i];
            if(c=='('||c=='['||c=='{')
            {
                if(i==s.length()-1)
                {
                    return false;
                }
                st.push(c);
                continue;
            }

            switch(c)
            {
                case ')':
                if(!st.empty()&&st.top()=='(')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
                case ']':
                if(!st.empty()&&st.top()=='[')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
                case '}':
                if(!st.empty()&&st.top()=='{')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }

        return st.empty() ? true : false;
    }
};
// @lc code=end

