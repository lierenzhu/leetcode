/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-08-16 15:29:39
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-08-16 16:15:24
 * @FilePath: \leetcode\135.分发糖果.cpp
 */
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i-1] < ratings[i])
            {
                candy[i] = candy[i-1] + 1;
            }
        }
        for (int i = ratings.size() - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
            {
                candy[i - 1] = max(candy[i - 1], candy[i] + 1);
            }
        }
        return std::accumulate(candy.begin(), candy.end(), 0);
    }
};
// @lc code=end
