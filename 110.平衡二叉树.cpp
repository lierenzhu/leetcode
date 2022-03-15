/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-15 09:30:10
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-15 10:12:18
 * @FilePath: /leetcode/110.平衡二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {

        if(depth(root)==-1)
        {
            return false;
        }
        else
        {
            return true;
        }

    }

    int depth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int left=depth(root->left);
        int right=depth(root->right);

        if(left==-1||right==-1||abs(left-right)>1)
        {
            return -1;
        }

        return max(left,right)+1;
    }
};
// @lc code=end

