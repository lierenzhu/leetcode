/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-03 19:37:08
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-03 22:23:53
 * @FilePath: /leetcode/932.漂亮数组.cpp
 */
/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * [932] 漂亮数组
 */

// @lc code=start
class Solution {
public:
    unordered_map<int,vector<int> > mp;
    vector<int> beautifulArray(int n) {

        if(mp.count(n)!=0)
        {
            return mp[n];
        }

        if(n==1)
        {
            return {1};
        }

        vector<int> result;
        int mid=(n+1)/2;

        vector<int> left=beautifulArray(mid);
        vector<int> right=beautifulArray(n-mid);

        for(int i:left)
        {
            result.push_back(2*i-1);
        }
        for(int i:right)
        {
            result.push_back(2*i);
        }

        mp[n]=result;

        return result;
    }
};
// @lc code=end

