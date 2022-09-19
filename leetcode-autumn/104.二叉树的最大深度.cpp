/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-19 10:34:14
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-19 10:46:28
 * @FilePath: /leetcode/leetcode-autumn/104.二叉树的最大深度.cpp
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        return maxDepth(root,0);

    }
    int maxDepth(TreeNode* root,int depth)
    {
        if(root==nullptr)
        {
            return depth;
        }
        int leftDepth=maxDepth(root->left,depth+1);
        int rightDepth=maxDepth(root->right,depth+1);
        return max(leftDepth,rightDepth);
    }
};
// @lc code=end

