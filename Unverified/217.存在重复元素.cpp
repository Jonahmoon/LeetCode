/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> temp;
        for (auto n:nums) {
            if (temp.find(n) != temp.end()) return true;
            else temp[n] = 1;
        }
        return false;
    }
};
// @lc code=end

