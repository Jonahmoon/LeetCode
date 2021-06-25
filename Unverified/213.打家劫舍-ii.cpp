/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
private:
    int rob_(vector<int>& nums, int i,int j){
        vector<int> dp(nums.size()+1,0);
        dp[i+1]=nums[i];
        for (int k=i+1;k<=j;k++) {
            dp[k+1] = max(dp[k-1]+nums[k],dp[k]);
        }
        return dp[j+1];
    }
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0],nums[1]);
        return max(rob_(nums,0,len-2),rob_(nums,1,len-1));
    }
};
// @lc code=end