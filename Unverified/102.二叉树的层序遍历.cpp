/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> array;
        toArray(root, array);
        return array;
    }
    void toArray(TreeNode* root, vector<vector<int>>& array) {
        std::queue<std::pair<TreeNode*, int>> q;
        q.push(std::pair(root, 0));
        while(!q.empty()) {
            auto k = q.front();
            if (k.second == array.size()) {
                std::vector<int> temp = {k.first->val};
                array.emplace_back(temp);
            }
            else {
                array[k.second].emplace_back(k.first->val);
            }
            if (k.first->left) q.push(std::pair(k.first->left, k.second+1));
            if (k.first->right) q.push(std::pair(k.first->right, k.second+1));
            q.pop();
        }
        return;
    }
};
// @lc code=end

