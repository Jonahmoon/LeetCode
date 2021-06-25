/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 直接走最大步， 贪心算法
        // 证明： i 的 最大步是 k, i<k，如果存在m , i + n[k] < i + n[m], 则 k 不是 i 的最大步，矛盾，所以不存在比最大步能达到的最远距离，每次取最大步即可。
        int position(0);
        int last_position(1);
        int max_step;
        while (position < nums.size()-1 && position != last_position) {
            last_position = position;
            max_step=0;
            if (nums[position] == 0) break;
            int max_jump = (nums.size()-1)<(position+nums[position])?nums.size()-1:position+nums[position];
            for (int i=position;i<=max_jump;i++) {
                if (nums[i]+i > max_step) {
                    max_step = nums[i]+i;
                    position=i;
                }
            }
        }
        if (position+nums[position] >= nums.size()-1) return true;
        return false;
    }
};
// @lc code=end

