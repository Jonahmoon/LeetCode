/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        int max(0),now(0);
        dfs(root, now, max);
        return max;
    }
    void dfs(TreeNode* root, int now, int &max) {
        if(!root) return;
        now = now+1;
        if(now > max) max = now;
        dfs(root->left, now, max);
        dfs(root->right, now, max);
        return;
    }
};
// @lc code=end

