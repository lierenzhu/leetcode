/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-15 16:23:24
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-15 16:56:13
 * @FilePath: /leetcode/437.路径总和-iii.cpp
 */
/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode* root, int targetSum) {

        if(!root) return 0;

        int count=rootSum(root, targetSum);

        count+=pathSum(root->left, targetSum);
        count+=pathSum(root->right, targetSum);

        return count;

    }

    int rootSum(TreeNode* root, int targetSum) {
        if(!root)
        {
            return 0;
        }

        int count = 0;
        if(root->val==targetSum)
        {
            count++;
        }
        count+=rootSum(root->left, targetSum-root->val);
        count+=rootSum(root->right, targetSum-root->val);
        return count;
    }
};
// @lc code=end

