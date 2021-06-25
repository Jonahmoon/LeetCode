/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return {{}};
        permute_(nums, result, 0);
        return result;
    }
    void permute_(vector<int>& nums, vector<vector<int>> &list, int i) {
        int len_ = nums.size();
        if (len_-1 == i) {
            list.emplace_back(nums);
        }
        std::set<int> num;
        for (int j=i; j < len_; j++) {
            if (num.find(nums[j]) == num.end() || i==j) {
                num.insert(nums[j]);
                swap(nums[i], nums[j]);
                permute_(nums, list, i+1);
                swap(nums[i], nums[j]);
            } 
        }
    }
};
// @lc code=end

