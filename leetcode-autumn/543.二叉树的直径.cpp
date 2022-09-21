/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-20 10:28:25
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-20 10:49:51
 * @FilePath: /leetcode/leetcode-autumn/543.二叉树的直径.cpp
 */
/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
#include "bits/stdc++.h"
using namespace std;

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        helper(root,diameter);
        return diameter;

    }
    int helper(TreeNode* root, int& diameter)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int left=helper(root->left, diameter);
        int right=helper(root->right,diameter);

        diameter=max(left+right,diameter);

        return max(left,right)+1;
    }
};
// @lc code=end

