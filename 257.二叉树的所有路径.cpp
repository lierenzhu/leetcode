/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-02-16 22:54:27
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-16 23:37:18
 * @FilePath: /leetcode/257.二叉树的所有路径.cpp
 */
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<int> path;
        vector<string> result;
        string pathStr;
        
        dfs(root, result, path,pathStr);

        return result;
    }

    void dfs(TreeNode* root, vector<string>& result, vector<int> &path, string &pathStr)
    {
        path.push_back(root->val);

        if(root->left==nullptr && root->right==nullptr)
        {
            for(int i : path)
            {
                pathStr+=to_string(i);
                pathStr+="->";
            }
            pathStr[pathStr.size()-2]='\0';
            result.push_back(pathStr);
            pathStr="";

            return;
        }

        if(root->left!=nullptr)
        {
            dfs(root->left, result, path,pathStr);
            path.pop_back();
        }
        if(root->right!= nullptr)
        {
            dfs(root->right, result, path,pathStr);
            path.pop_back();
        }
    }
};
// @lc code=end

