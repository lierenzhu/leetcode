/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-16 22:16:18
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-16 22:42:56
 * @FilePath: /leetcode/572.另一棵树的子树.cpp
 */
/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        return dfs(root,subRoot);

    }

    bool dfs(TreeNode* root, TreeNode* subRoot) {

        if(!root)
        {
            return false;
        }

        return comp(root,subRoot)||dfs(root->left,subRoot)||dfs(root->right,subRoot);

    }

    bool comp(TreeNode* root, TreeNode* subRoot)
    {
        if(!root&&!subRoot)
        {
            return true;
        }
        else if(!root||!subRoot)
        {
            return false;
        }

        if(root->val==subRoot->val)
        {
            return comp(root->left,subRoot->left)&&comp(root->right,subRoot->right);
        }
        else
        {
            return false;
        }

    }
};
// @lc code=end

