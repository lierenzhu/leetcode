/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-15 17:06:57
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-15 17:18:49
 * @FilePath: /leetcode/101.对称二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {

        if(!root)
        {
            return true;
        }
        else
        {
            return isSymmetric(root->left,root->right);
        }

    }

    bool isSymmetric(TreeNode* left,TreeNode* right) {
        if(!left&&!right)
        {
            return true;
        }
        if(!left||!right)
        {
            return false;
        }
        if(left->val!=right->val)
        {
            return false;
        }
        
        return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }
};
// @lc code=end

