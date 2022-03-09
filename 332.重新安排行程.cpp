/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-09 09:16:53
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-09 10:07:21
 * @FilePath: /leetcode/332.重新安排行程.cpp
 */
/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        vector<string> ans;
        unordered_map<string, multiset<string>> path;

        for(const auto & ticket : tickets)
        {
            path[ticket[0]].insert(ticket[1]);
        }

        stack<string> s;
        s.push("JFK");

        while(!s.empty())
        {
            string next=s.top();
            if(path[next].empty())
            {
                ans.push_back(next);
                s.pop();
            }
            else
            {
                s.push(*(path[next].begin()));
                path[next].erase(path[next].begin());
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};
// @lc code=end

