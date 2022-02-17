/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-17 23:46:03
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-17 23:52:19
 * @FilePath: /leetcode/70.爬楼梯.cpp
 */
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {

        int pre1=2,pre2=1,cur;
        if(n<=2)
        {
            return n;
        }
        for(int i=2;i<n;++i)
        {
            cur=pre2+pre1;
            pre2=pre1;
            pre1=cur;
        }
        return cur;
    }
};
// @lc code=end

