/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-01-15 23:37:00
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-01-16 00:02:07
 * @FilePath: /leetcode/79.单词搜索.cpp
 */
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
        {
            return false;
        }

        bool find=false;
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                backtrace(i,j,board,word,find,visited,0);
            }
        }

        return find;

    }

    void backtrace(int i, int j,vector<vector<char>> &board,string &word,bool &find,vector<vector<bool>> &visited,int pos)
    {
        if(i<0||i>=board.size()||j<0||j>=board[0].size())
        {
            return;
        }
        if(visited[i][j]||find||board[i][j]!=word[pos])
        {
            return;
        }

        if(pos==word.size()-1)
        {
            find = true;
            return;
        }

        visited[i][j]=true;

        backtrace(i+1,j,board,word,find,visited,pos+1);
        backtrace(i-1,j,board,word,find,visited,pos+1);
        backtrace(i,j+1,board,word,find,visited,pos+1);
        backtrace(i,j-1,board,word,find,visited,pos+1);
        visited[i][j]=false;

    }
};
// @lc code=end

