/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-14 10:53:05
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-14 11:27:35
 * @FilePath: /leetcode/leetcode-autumn/105.从前序与中序遍历序列构造二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;++i)
        {
            index[inorder[i]]=i;
        }

        return buildTree(preorder,inorder,0,n-1,0,n-1);

    }

    TreeNode* buildTree(vector<int>& preorder,vector<int> &inorder, int preorder_left, int preorder_right,int inorder_left, int inorder_right){
        if(preorder_left>preorder_right)
        {
            return nullptr;
        }
        int preorder_root=preorder_left;
        int inorder_root=index[preorder[preorder_root]];

        TreeNode *root=new TreeNode(preorder[preorder_root]);
        int left_tree_size=inorder_root-inorder_left;
        root->left=buildTree(preorder,inorder,preorder_root+1,preorder_root+left_tree_size,inorder_left,inorder_root-1);
        root->right=buildTree(preorder,inorder,preorder_root+left_tree_size+1,preorder_right,inorder_root+1,inorder_right);

        return root;
    }
private:
    unordered_map<int,int> index;
};
// @lc code=end

