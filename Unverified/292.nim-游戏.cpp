/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        // 很好理解，两个人每轮一共可以拿2~6块石头，因为你是后手，所以你可以确保每轮拿的石头总数为4
        // 如果数字不是4的倍数：大于4，n mode 4一定小于4，你只要第一次拿走余数就可以赢，小于4，还用说吗；如果数字是4的倍数，那么就相当于你把后手让给了对面，肯定是输的。
        if (n%4 ==0) return false;
        return true;
    }
};
// @lc code=end

