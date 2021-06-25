/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 先二分查找，再前后遍历
        size_t len = nums.size();
        if (len == 0) return {-1, -1};
        if (len == 1) {
            if (nums[0] == target) return {0, 0};
            return {-1, -1};
        }
        vector<int> re = {-1, -1};
        int low(0),high(len-1);
        while(high >= low) {
            int mid = (high + low) / 2;
            if (nums[mid] == target) {
                int i(mid);
                while(i >= 0) {
                    if (nums[i] != target) break;
                    i--;
                }
                re[0] = i+1;
                i = mid;
                while(i < len) {
                    if (nums[i] != target) break;
                    i++;
                }
                re[1] = i-1; 
            }
            if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return re;
    }
};
// @lc code=end

