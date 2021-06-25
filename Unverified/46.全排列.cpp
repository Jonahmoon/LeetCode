/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return {{}};
        permute_(nums, result, 0);
        return result;
    }
    void permute_(vector<int>& nums, vector<vector<int>> &result, int i) {
        int len_ = nums.size();
        if (len_-1 == i) {
            result.emplace_back(nums);
        }
        for (int j=i; j < len_; j++) {
            swap(nums[i], nums[j]);
            permute_(nums, result, i+1);
            swap(nums[i], nums[j]);
        }
    }
};
// @lc code=end

