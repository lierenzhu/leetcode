/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-03-08 19:24:04
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-08 20:01:53
 * @FilePath: /leetcode/149.直线上最多的点数.cpp
 */
/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        unordered_map<double, int> hash;
        int same_xy, same_x;
        int max_count = 0;

        for (int i = 0; i < points.size(); ++i)
        {
            same_xy = 1;
            same_x = 1;
            for (int j = i + 1; j < points.size(); ++j)
            {
                if (points[i][0] == points[j][0])
                {
                    same_x++;
                    if (points[i][1] == points[j][1])
                    {
                        same_xy++;
                    }
                }
                else
                {
                    double dy = points[j][1] - points[i][1];
                    double dx = points[j][0] - points[i][0];
                    hash[dy / dx]++;
                }
            }
            max_count = max(max_count, same_x);

            for (auto item : hash)
            {
                max_count = max(max_count, same_xy + item.second);
            }
            hash.clear();
        }
        return max_count;
    }
};
// @lc code=end
