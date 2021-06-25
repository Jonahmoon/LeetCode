/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        vector<int> left;
        vector<int> right;
        toArrayleft(root->left, left);
        toArrayright(root->right, right);
        for (auto i:left) cout << i << " ";
        cout << endl;
        for (auto i:right) cout << i << " "; 
        return left == right;
    }
    void toArrayleft(TreeNode* root, vector<int> &array) {
        std::queue<TreeNode*> q;
        if (!root) {
            array.emplace_back(-1);
            return;
        }
        q.push(root);
        while(!q.empty()){
            if (!q.front()) array.emplace_back(-1);
            else array.emplace_back(q.front()->val);
            if (q.front()) {
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
        return;
    }
    void toArrayright(TreeNode* root, vector<int> &array) {
        std::queue<TreeNode*> q;
        if (!root) {
            array.emplace_back(-1);
            return;
        }
        q.push(root);
        while(!q.empty()){
            if (!q.front()) array.emplace_back(-1);
            else array.emplace_back(q.front()->val);
            if (q.front()) {
                q.push(q.front()->right);
                q.push(q.front()->left);
            }
            q.pop();
        }
        return;
    }
};
// @lc code=end

