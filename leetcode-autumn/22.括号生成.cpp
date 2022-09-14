/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-14 10:17:42
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-14 10:48:04
 * @FilePath: /leetcode/leetcode-autumn/22.括号生成.cpp
 */
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    void backtrack(vector<string> &result, string &cur, int open, int close, int n)
    {
        if(cur.size()==2*n)
        {
            result.push_back(cur);
            return;
        }
        if(open<n)
        {
            cur.push_back('(');
            backtrack(result,cur,open+1,close,n);
            cur.pop_back();
        }
        if(close<open)
        {
            cur.push_back(')');
            backtrack(result,cur,open,close+1,n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur;
        backtrack(result,cur,0,0,n);
        return result;

    }
};
// @lc code=end

