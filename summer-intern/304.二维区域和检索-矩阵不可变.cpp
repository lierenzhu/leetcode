/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-09 16:58:44
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-09 17:23:42
 * @FilePath: /leetcode/304.二维区域和检索-矩阵不可变.cpp
 */
/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) :psum(matrix.size()+1,vector<int>(matrix[0].size()+1,0)) {

        for(int i = 1; i <= matrix.size();++i)
        {
            for(int j = 1; j <= matrix[0].size();++j)
            {
                psum[i][j]=matrix[i-1][j-1]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return psum[row2+1][col2+1]-psum[row1][col2+1]-psum[row2+1][col1]+psum[row1][col1];

    }

    vector<vector<int>> psum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

