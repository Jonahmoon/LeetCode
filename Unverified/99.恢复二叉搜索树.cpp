/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
private:
    TreeNode *visit;
    TreeNode *lastvisit;
    TreeNode *first;
    TreeNode *second;

    void midTraverse(TreeNode* root) {
        if (root) {
            midTraverse(root->left);
            visit = root;
            if (lastvisit) {
                if (visit->val < lastvisit->val) {
                    if (!first) {
                        first = lastvisit;
                        second = visit;
                    }
                    else second = visit;
                }
            }
            lastvisit = visit;
            midTraverse(root->right);
        }
    }
public:
    Solution():visit(nullptr), lastvisit(nullptr), first(nullptr), second(nullptr){}
    void recoverTree(TreeNode* root) {
        midTraverse(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};
// @lc code=end

