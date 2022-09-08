/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-08 09:40:27
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-08 10:13:07
 * @FilePath: /leetcode/leetcode-autumn/236.二叉树的最近公共祖先.cpp
 */
/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
        {
            return root;
        }
        if(root->val==p->val||root->val==q->val)
        {
            return root;
        }
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left==nullptr)
        {
            return right;
        }
        if(right==nullptr)
        {
            return left;
        }
        if(left&&right)
        {
            return root;
        }
        return nullptr;
    }
};
// @lc code=end

