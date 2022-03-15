/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-15 15:45:31
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-15 16:11:57
 * @FilePath: /leetcode/543.二叉树的直径.cpp
 */
/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        searchTree(root, diameter);
        return diameter;

    }

    int searchTree(TreeNode* root, int& diameter){
        if(!root)
        {
            return 0;
        }
        int left=searchTree(root->left,diameter);
        int right=searchTree(root->right,diameter);

        diameter = max(left+right,diameter);
        return max(left,right)+1;
    }
};
// @lc code=end

