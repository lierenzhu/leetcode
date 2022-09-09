/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-09 16:47:05
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-09 16:56:15
 * @FilePath: /leetcode/leetcode-autumn/94.二叉树的中序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void inorderTraversal(TreeNode* root, vector<int> &result){
        if(root==nullptr)
        {
            return;
        }
        inorderTraversal(root->left,result);
        result.push_back(root->val);
        inorderTraversal(root->right,result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversal(root,result);
        return result;

    }
};
// @lc code=end

