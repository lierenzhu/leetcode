/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-09 16:57:20
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-09 17:22:17
 * @FilePath: /leetcode/leetcode-autumn/56.合并区间.cpp
 */
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(),intervals.end());

        for(vector<int> interval:intervals)
        {
            if(result.empty())
            {
                result.push_back(interval);
                continue;
            }
            if(result.back()[1]>=interval[0])
            {
                result.back()[1]=max(interval[1],result.back()[1]);
            }else{
                result.push_back(interval);
            }
        }

        return result;

    }
};
// @lc code=end

