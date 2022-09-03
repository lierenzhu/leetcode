/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-15 09:15:40
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-15 09:22:55
 * @FilePath: /leetcode/104.二叉树的最大深度.cpp
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {

        if(root)
        {
            int left=maxDepth(root->left);
            int right=maxDepth(root->right);
            return max(left,right)+1;
        }
        else
        {
            return 0;
        }

    }
};
// @lc code=end

