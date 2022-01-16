/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-01-16 23:15:50
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-01-16 23:59:37
 * @FilePath: /leetcode/51.n-皇后.cpp
 */
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;

        if(n==0)
        {
            return result;
        }

        vector<string> board(n,string(n,'.'));
        vector<bool> column(n,false),dig(2*n-1,false),udig(2*n-1,false);

        backtrace(result,board,column,dig,udig,0,n);

        return result;
    }

    void backtrace(vector<vector<string>> &result, vector<string> &board,vector<bool> &column,vector<bool> &dig,vector<bool> &udig,int row,int n)
    {
        if(row==n)
        {
            result.push_back(board);
        }

        for(int i=0;i<n;++i)
        {
            if(column[i]||dig[n-row+i-1]||udig[row+i])
            {
                continue;
            }
        board[row][i]='Q';
        column[i]=dig[n-row+i-1]=udig[row+i]=true;
        backtrace(result,board,column,dig,udig,row+1,n);
        board[row][i]='.';
        column[i]=dig[n-row+i-1]=udig[row+i]=false;
        }


    } 
};
// @lc code=end

