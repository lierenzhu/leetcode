/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        calSum(root,sum,false);
        return sum;

    }

    void calSum(TreeNode* root,int& sum,bool isLeft)
    {
        if(!root)
        {
            return;
        }

        if(isLeft&&!root->left&&!root->right)
        {
            sum+=root->val;
        }
        calSum(root->left,sum,true);
        calSum(root->right,sum,false);
    }
};
// @lc code=end

