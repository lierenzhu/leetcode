/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-06 15:54:05
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-06 16:50:46
 * @FilePath: /leetcode/739.每日温度.cpp
 */
/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int days=temperatures.size();
        vector<int> ans(days);
        stack<int> st;

        for(int i=0;i<days;++i)
        {
            while(!st.empty())
            {
                int pre_day=st.top();
                if(temperatures[i]<=temperatures[pre_day])
                {
                    break;
                }
                st.pop();
                ans[pre_day]=i-pre_day;
            }

            st.push(i);
        }
        return ans;

    }
};
// @lc code=end

