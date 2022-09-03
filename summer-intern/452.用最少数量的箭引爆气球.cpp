/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-08-23 15:51:55
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-08-23 16:53:30
 * @FilePath: /e:\code\Cpp\leetcodee:\code\Cpp\leetcode/452.用最少数量的箭引爆气球.cpp
 */
/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    static bool sortRight(const vector<int> &a, const vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(), points.end(),sortRight);
        int result = 1;
        int arrow=points[0][1];

        for(int i = 0; i < points.size();i++)
        {
            if(points[i][0]<=arrow)
                continue;
            else
            {
                result++;
                arrow=points[i][1];
            }
        }
        return result;

    }
};
// @lc code=end

