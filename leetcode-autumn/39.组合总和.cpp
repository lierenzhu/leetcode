/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-20 11:14:56
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-20 11:34:35
 * @FilePath: /leetcode/leetcode-autumn/39.组合总和.cpp
 */
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> cur;
        backtrack(candidates,target,cur,0,0,result);
        
        return result;
    }

    void backtrack(vector<int>& candidates,int target,vector<int>& cur,int begin, int sum, vector<vector<int>>& result)
    {
        if(sum==target)
        {
            result.push_back(cur);
            return;
        }
        if(sum>target)
        {
            return;
        }

        for(int i=begin;i<candidates.size();++i)
        {
            cur.push_back(candidates[i]);
            backtrack(candidates,target,cur,i,sum+candidates[i],result);
            cur.pop_back();
        }
    }
};
// @lc code=end

