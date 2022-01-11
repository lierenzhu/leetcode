/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-01-11 21:48:41
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-01-11 22:18:34
 * @FilePath: /leetcode/417.太平洋大西洋水流问题.cpp
 */
/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:
    vector<int> direction={-1,0,1,0,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty()|| heights[0].empty())
        {
            return {};
        }
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> result;

        vector<vector<bool>> can_reach_p(m,vector<bool>(n,false));
        vector<vector<bool>> can_reach_a(m,vector<bool>(n,false));
        
        for(int i = 0; i < m; ++i)
        {
            dfs(heights,can_reach_p,i,0);
            dfs(heights,can_reach_a,i,n-1);
        }
        for(int j=0;j<n; ++j)
        {
            dfs(heights,can_reach_p,0,j);
            dfs(heights,can_reach_a,m-1,j);
        }

        for(int k=0;k<m; ++k)
        {
            for (int l = 0; l < n; l++)
            {
                if(can_reach_a[k][l]&&can_reach_p[k][l])
                {
                    result.push_back(vector<int>{k,l});
                }
            }
            
        }
        return result;

    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& can_reach, int r, int c)
    {
        if(can_reach[r][c])
        {
            return;
        }

        can_reach[r][c] = true;

        for(int i = 0; i < 4; ++i)
        {
            int x = r+direction[i];
            int y=c+direction[i+1];

            if(x>=0&&x<heights.size()&&y>=0&&y<heights[0].size()&&heights[x][y]>=heights[r][c])
            {
                dfs(heights,can_reach,x,y);
            }
        }

    }
};
// @lc code=end

