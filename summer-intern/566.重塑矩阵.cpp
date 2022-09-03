/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-10 15:41:21
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-10 16:04:57
 * @FilePath: /leetcode/566.重塑矩阵.cpp
 */
/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

//咱就只会个暴力了
        // int m=mat.size(),n=mat[0].size();
        // if(m*n!=r*c)
        // {
        //     return mat;
        // }

        // vector<int> temp;
        // for(vector<int> &i:mat)
        // {
        //     for(int j:i)
        //     {
        //         temp.push_back(j);
        //     }
        // }
        // vector<vector<int>> ans(r,vector<int>(c,0));
        // int p=0;
        
        // for(int i=0;i<r;++i)
        // {
        //     for(int j=0;j<c;++j)
        //     {
        //         ans[i][j]=temp[p++];
        //     }
        // }

        // return ans;
//二维数组排扁为一维
        int m=mat.size(),n=mat[0].size();
        if(m*n!=r*c)
        {
            return mat;
        }
        vector<vector<int>> ans(r,vector<int>(c));

        for(int i=0;i<m*n;++i)
        {
            ans[i/c][i%c]=mat[i/n][i%n];
        }

        return ans;

        

    }
};
// @lc code=end

