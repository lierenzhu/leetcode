/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-17 09:32:24
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-17 09:59:23
 * @FilePath: /leetcode/513.找树左下角的值.cpp
 */
/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int left_value;
    int max_depth=INT_MIN;
    int findBottomLeftValue(TreeNode* root) {
        goLeft(root,0);
        return left_value;
    }

    void goLeft(TreeNode* root, int cur_depth) {
        if(!root->left&&!root->right)
        {
            if(cur_depth>max_depth)
            {
                max_depth=cur_depth;
                left_value=root->val;
            }
            return;
        }
        if(root->left)
        {
            cur_depth++;
            goLeft(root->left,cur_depth);
            cur_depth--;
        }
        if(root->right)
        {
            cur_depth++;
            goLeft(root->right,cur_depth);
            cur_depth--;
        }

        return;
    }
};
// @lc code=end

