/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-15 22:40:24
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-15 23:53:28
 * @FilePath: /leetcode/130.被围绕的区域.cpp
 */
/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:

    vector<int> direction = {-1, 0, 1, 0, -1};

    void solve(vector<vector<char>>& board) {

        int m=board.size(),n = board[0].size();
        
        vector<vector<bool> > srounded(m,vector<bool>(n,true));

        for(int i=0;i<m;i++)
        {
            dfs(board,srounded,i,0);
            dfs(board,srounded,i,n-1);
        }
        for(int i=0;i<n;i++)
        {
            dfs(board,srounded,0,i);
            dfs(board,srounded,m-1,i);
        }
        
        for(int i=0;i<m; i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O'&&srounded[i][j])
                {
                    board[i][j]='X';
                }
            }
        }

    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& srounded, int r, int c)
    {
        if(!srounded[r][c]||board[r][c]=='X')
        {
            return;
        }

        srounded[r][c]=false;

        for(int i=0; i<4; i++)
        {
            int x= r + direction[i], y= c + direction[i+1];

            if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&board[x][y]=='O')
            {
                dfs(board,srounded,x,y);
            }
        }
    }
};
// @lc code=end

