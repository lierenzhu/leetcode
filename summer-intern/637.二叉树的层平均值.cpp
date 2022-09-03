/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-15 21:36:51
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-15 21:44:41
 * @FilePath: /leetcode/637.二叉树的层平均值.cpp
 */
/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        if(!root)
        {
            return ans;
        }

        q.push(root);
        while(!q.empty())
        {
            int count=q.size();
            double sum=0;
            for(int i=0;i<count;++i)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }

                sum+=node->val;
            }
            ans.push_back(sum/count);
        }

        return ans;
    }
};
// @lc code=end

