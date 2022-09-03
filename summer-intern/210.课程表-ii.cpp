/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-17 14:44:17
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-17 15:15:20
 * @FilePath: /leetcode/210.课程表-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0),ans;
        vector<vector<int>> afterrequisites(numCourses,vector<int>());

        for(const auto prerequisite:prerequisites)
        {
            afterrequisites[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }


        queue<int> q;

        for(int i=0;i<numCourses;++i)
        {
            if(!indegree[i])
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int u=q.front();
            ans.push_back(u);
            q.pop();

            for(int i:afterrequisites[u])
            {
                indegree[i]--;
                if(!indegree[i])
                {
                    q.push(i);
                }
            }
        }
        for(int i:indegree)
        {
            if(i)
            {
                return vector<int>();
            }
        }

        return ans;


    }
};
// @lc code=end

