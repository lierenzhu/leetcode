/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-15 20:01:43
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-15 20:51:53
 * @FilePath: /leetcode/1110.删点成林.cpp
 */
/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> forest;
        unordered_set<int> hash(to_delete.begin(), to_delete.end());

        root=searchNode(root, hash,forest);
        if(root)
        {
            forest.push_back(root);
        }
        
        return forest;
    }

    TreeNode* searchNode(TreeNode* root, unordered_set<int>& hash,vector<TreeNode*>& forest){
        if(!root)
        {
            return root;
        }

        root->left=searchNode(root->left, hash, forest);
        root->right=searchNode(root->right, hash, forest);

        if(hash.count(root->val))
        {
            if(root->left)
            {
                forest.push_back(root->left);
            }
            if(root->right)
            {
                forest.push_back(root->right);
            }

            root=nullptr;
        }

        return root;
    }

};
// @lc code=end

