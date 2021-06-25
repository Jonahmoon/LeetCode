/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i(0),j(0);
        size_t len = nums.size();
        while(j < len) {
            if (nums[j] != val) nums[i++] = nums[j];
            j++;
        }
        return i;
    }
};
// @lc code=end

