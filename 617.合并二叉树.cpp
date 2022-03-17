/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-16 21:21:47
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-16 22:14:20
 * @FilePath: /leetcode/617.合并二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        TreeNode* merged=new TreeNode();

        if(!root1)
        {
            return root2;
        }
        if(!root2)
        {
            return root1;
        }

        merged->val=root1->val+root2->val;

        merged->left=mergeTrees(root1->left,root2->left);
        merged->right=mergeTrees(root1->right,root2->right);

        return merged;

    }
};
// @lc code=end

