/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int re = (n+1)*n/2;
        for (auto i:nums) re -= i;
        return re;
    }
};
// @lc code=end

