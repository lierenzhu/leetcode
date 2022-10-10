/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-10-10 21:21:46
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-10-10 21:44:00
 * @FilePath: /leetcode/leetcode-autumn/240.搜索二维矩阵-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=n-1;
        while(i<m&&j>=0)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]>target)
            {
                --j;
            }
            else
            {
                ++i;
            }
        }
        return false;
    }
};
// @lc code=end

