/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    void backtrace(vector<int>& candidates, int begin, int target, vector<int> ans, vector<vector<int>> &result) {
        for (size_t i=begin; i < candidates.size(); i++) {
            if (candidates[i] == target) {
                ans.emplace_back(target);
                result.emplace_back(ans);
                ans.pop_back();
            }
            else if(candidates[i] > target){
                continue;
            }
            else {
                ans.emplace_back(candidates[i]);
                backtrace(candidates, i, target-candidates[i], ans, result);
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        backtrace(candidates, 0, target, ans, result);
        return result;
    }
};
// @lc code=end

