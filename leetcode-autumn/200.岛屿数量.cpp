/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-07 09:32:41
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-07 09:59:43
 * @FilePath: /leetcode/leetcode-autumn/200.岛屿数量.cpp
 */
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int result=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    result++;
                }
            }
        }
        return result;
    }
private:
    vector<int> direction{-1,0,1,0,-1};
    void dfs(vector<vector<char>> &grid,int i,int j)
    {
        grid[i][j]='0';
        for(int k=0;k<4;++k)
        {
            int x=i+direction[k],y=j+direction[k+1];
            if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]=='1')
            {
                dfs(grid,x,y);
            }
        }

    }
};
// @lc code=end

