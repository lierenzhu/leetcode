/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-02-19 10:05:54
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-19 11:43:25
 * @FilePath: /leetcode/542.01-矩阵.cpp
 */
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // DP
        // int m = mat.size(), n = mat[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));

        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         if (mat[i][j] == 0)
        //         {
        //             dp[i][j] = 0;
        //         }
        //         else
        //         {
        //             if (i > 0)
        //             {
        //                 dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        //             }
        //             if (j > 0)
        //             {
        //                 dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        //             }
        //         }
        //     }
        // }
        // for (int i = m - 1; i >= 0; --i)
        // {
        //     for (int j = n - 1; j >= 0; --j)
        //     {
        //         if (i < m - 1)
        //         {
        //             dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
        //         }
        //         if (j < n - 1)
        //         {
        //             dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
        //         }
        //     }
        // }
        // return dp;

        //BFS
        vector<int> direction = {-1, 0, 1, 0, -1};
        int m=mat.size(),n = mat[0].size();
        queue<pair<int, int>> points;

        for(int i=0; i < m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(mat[i][j]==0)
                {
                    points.push(make_pair(i,j));
                }
                else
                {
                    mat[i][j]=-1;
                }
            }
        }

        while(!points.empty())
        {
            auto p = points.front();
            points.pop();

            for(int i=0;i<4;++i)
            {
                int x=p.first+direction[i];
                int y=p.second+direction[i+1];

                if(x>=0&&x<m&&y>=0&&y<n&&mat[x][y]==-1)
                {
                    mat[x][y] = mat[p.first][p.second]+1;
                    points.push(make_pair(x,y));
                }
            }

        }

        return mat;
    }
};
// @lc code=end
