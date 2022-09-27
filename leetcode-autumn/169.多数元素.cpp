/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> count;
        int half=nums.size()/2;
        for(int i:nums)
        {
            count[i]++;
            if(count[i]>half)
            {
                return i;
            }
        }
        
        return 0;


    }
};
// @lc code=end

