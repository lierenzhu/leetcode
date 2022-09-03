/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m=matrix.size(),n = matrix[0].size();

        int i=0,j=n-1;

        while(i>=0&&j>=0&&i<m&&j<n)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]>target)
            {
                j--;
                continue;
            }
            else if(matrix[i][j]<target)
            {
                i++;
                continue;
            }
        }
        
        return false;
    }
};
// @lc code=end

