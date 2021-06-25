/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
/*
      2
    1  4
  7 4  8 3
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
// 其他方法：因为二叉搜索树可视为排好序的，所以使用中序遍历可以得到升序数组，只要检测是否是升序就可以
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST_internel(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST_internel(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return isValidBST_internel(root -> left, lower, root -> val) && isValidBST_internel(root -> right, root -> val, upper);
    }
};
// @lc code=end

