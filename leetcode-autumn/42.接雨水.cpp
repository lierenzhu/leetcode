/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-08 20:55:40
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-08 21:13:56
 * @FilePath: /leetcode/leetcode-autumn/42.接雨水.cpp
 */
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        int highestIndex=0;
        for(int i=0;i<len;++i)
        {
            if(height[i]>height[highestIndex])
            {
                highestIndex=i;
            }
        }
        int left=0,right=0;
        int result=0;
        for(int i=1;i<highestIndex;++i)
        {
            left=max(left,height[i-1]);
            if(height[i]<left)
            {
                result+=left-height[i];
            }
        }
        for(int i=len-2;i>highestIndex;--i)
        {
            right=max(right,height[i+1]);
            if(height[i]<right)
            {
                result+=right-height[i];
            }
        }
        return result;
    }
};
// @lc code=end

