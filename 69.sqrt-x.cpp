/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-10-12 10:28:26
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-10-12 14:55:56
 * @FilePath: /Code/leetcode/69.sqrt-x.cpp
 */
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {

        int l = 1, r = x;
        int mid = l + (r - l) / 2;
        int sqrt;

        if(x==0)
        {
            return x;
        }

        while (l <= r)
        {
            sqrt = x / mid;
            if (sqrt == mid)
            {
                return sqrt;
            }
            else if (sqrt < mid)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            mid = l + (r - l) / 2;
        }
        return r;
    }
};
// @lc code=end
