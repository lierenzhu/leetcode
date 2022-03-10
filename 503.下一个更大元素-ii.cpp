/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-10 21:45:56
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-10 22:22:28
 * @FilePath: /leetcode/503.下一个更大元素-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> ans(n,-1);

        for(int i=0;i<n*2-1;++i)
        {
            while(!st.empty())
            {
                int pre=st.top();
                if(nums[i%n]<=nums[pre])
                {
                    break;
                }
                ans[pre]=nums[i%n];
                st.pop();
            }

            st.push(i%n);
        }

        return ans;
    }
};
// @lc code=end

