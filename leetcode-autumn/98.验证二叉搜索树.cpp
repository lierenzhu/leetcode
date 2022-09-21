/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-20 09:41:05
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-20 10:26:17
 * @FilePath: /leetcode/leetcode-autumn/98.验证二叉搜索树.cpp
 */
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    bool isValidBST(TreeNode* root) {
        // return isValidBST(root,LONG_MIN,LONG_MAX);
        return inorder(root);
    }
    bool isValidBST(TreeNode* root, long lower, long upper)
    {
        if(root==nullptr)
        {
            return true;
        }
        if(root->val<=lower||root->val>=upper)
        {
            return false;
        }
        return isValidBST(root->left,lower,root->val)&&isValidBST(root->right,root->val,upper);

    }
    long pre=LONG_MIN;

    bool inorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return true;
        }
        bool left=inorder(root->left);
        if(pre>=root->val)
        {
            return false;
        }
        pre=root->val;
        bool right=inorder(root->right);

        return left&&right;
    }
};
// @lc code=end

