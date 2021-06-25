/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
private:
    void backtrace(vector<int> &can, int pos, int target, vector<int> tmp, vector<vector<int>> &result) {
        for (size_t i(pos); i < can.size(); i++) {
            if (can[i] > target || (i > pos && can[i] == can[i-1])) continue; // 这里判断条件的第二部分是为了剪枝
            if (can[i] == target) {
                tmp.emplace_back(can[i]);
                result.emplace_back(tmp);
                tmp.pop_back();
            } else {
                tmp.emplace_back(can[i]);
                backtrace(can, i+1, target-can[i], tmp, result);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> tmp; // to save ans of one trace
        backtrace(candidates, 0, target, tmp, result);
        return result;
    }
};
// @lc code=end

