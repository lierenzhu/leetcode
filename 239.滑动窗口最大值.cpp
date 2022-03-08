/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-08 09:22:12
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-08 10:48:09
 * @FilePath: /leetcode/239.滑动窗口最大值.cpp
 */
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // //使用优先级队列
        // priority_queue<pair<int, int> >max_q;
        // vector<int> ans;

        // for(int i=0;i<k;++i)
        // {
        //     max_q.push(make_pair(nums[i],i));
        // }
        // ans.push_back(max_q.top().first);

        // for(int i=k;i<nums.size();++i)
        // {
        //     max_q.push(make_pair(nums[i],i));
        //     while(max_q.top().second<=i-k)
        //     {
        //         max_q.pop();
        //     }

        //     ans.push_back(max_q.top().first);
        // }

        // return ans;

        //使用双端队列
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<k;++i)
        {
            while(!dq.empty()&&nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for(int i=k;i<nums.size();++i)
        {
            if(!dq.empty()&&dq.front()<=i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty()&&nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
// @lc code=end

