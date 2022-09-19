/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-09-19 10:46:59
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-19 11:18:23
 * @FilePath: /leetcode/leetcode-autumn/78.子集.cpp
 */
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, result, current, 0);
        return result;
    }

    void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> current, int start)
    {
        result.push_back(current);
        for (int i = start; i < nums.size(); ++i)
        {
            current.push_back(nums[i]);
            backtrack(nums, result, current,i + 1);
            current.pop_back();
        }
    }
};
// @lc code=end
