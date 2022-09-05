/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-05 11:05:31
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-05 15:10:21
 * @FilePath: /leetcode/leetcode-autumn/102.二叉树的层序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr)
        {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        int curSize=1;
        int nextSize=0;
        vector<int> curLevel;
        while(!q.empty()){
            TreeNode *curNode=q.front();
            q.pop();
            curSize--;
            curLevel.push_back(curNode->val);
            if(curNode->left!=nullptr){
                q.push(curNode->left);
                ++nextSize;
            }
            if(curNode->right!=nullptr){
                q.push(curNode->right);
                ++nextSize;
            }
            if(curSize==0){
                result.push_back(curLevel);
                curLevel.clear();
                curSize=nextSize;
                nextSize=0;
            }
        }
        return result;

    }
};
// @lc code=end

