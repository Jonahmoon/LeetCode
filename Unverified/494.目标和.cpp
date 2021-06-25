/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
private:
    // dfs + backtrace
    void backtrace(vector<int>& nums, int target, int pos, int& result) {
        if (pos == nums.size() - 1 && abs(target) == abs(nums[pos])) {
            if (target == 0) result += 2;
            else result++;
            return;
        }
        if (pos < nums.size() - 1) {
            backtrace(nums, target+abs(nums[pos]), pos + 1, result);
            backtrace(nums, target-abs(nums[pos]), pos + 1, result);
        }
        return;
    }
public:
    // dfs
    /*
    int findTargetSumWays(vector<int>& nums, int target) {
        int result = 0;
        backtrace(nums, target, 0, result);
        return result;
    }
    */

    // dp
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int n = nums.size(), neg = diff / 2;
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= num) {
                    dp[i][j] += dp[i - 1][j - num];
                }
            }
        }
        return dp[n][neg];

        /* 缩减dp数组的版本
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 != 0 || target > sum) return 0;
        int pos = (sum + target) / 2;
        vector<int> dp(pos+1, 0);
        dp[0] = 1;
        for (size_t i=0; i < nums.size(); i++) {
            for (int j = pos; j >= nums[i]; j--) { 
                // 内层循环需采用倒序遍历的方式，这种方式保证转移来的是 dp[i-1][] 中的元素值
                // 这里采用了滚动数组的方法，我们可以对比上文代码，发现dp数组只参考了上一层的dp数组，那么我们就可以使用原地算法，复用空间
                // 显然，如果正序遍历，就会覆盖之前的内容，而倒序遍历则不会
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[pos];
        */
    }
};
// @lc code=end

