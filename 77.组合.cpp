/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-01-14 23:22:43
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-01-14 23:49:28
 * @FilePath: /leetcode/77.组合.cpp
 */
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> result;
        vector<int> comb(k,0);
        int count = 0;
        int pos = 1;
        backtrace(result,comb,count,pos,n,k);

        return result;

    }

    void backtrace(vector<vector<int>> &result, vector<int> &comb, int count, int pos, int n, int k)
    {
        if(count==k)
        {
            result.push_back(comb);
            return;
        }

        for(int i=pos;i<=n;++i)
        {
            comb[count++]=i;
            backtrace(result,comb,count,i+1,n,k);
            count--;
        }
    }
};
// @lc code=end

