/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low(0),high(nums.size()-1);
        int mid;
        while(high > low) {
            mid = (high+low)/2;
            if (nums[mid] > nums[mid+1]) high = mid; // 根据mid处在上坡还是下坡做出判断，确保剩下的区间包含更大的数
            else low = mid+1;
        }
        return low;
    }
};
// @lc code=end

