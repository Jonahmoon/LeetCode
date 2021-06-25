/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
private:
    bool can(int &rest, long divisor) {
        if (rest == INT_MIN) {
            if (divisor < 0) return rest<=divisor;
            else return INT_MAX >= divisor;
        }
        else return abs(rest) >= abs(divisor);
    }
    void getRest(int &dividend, int &close, int &rest) {
        if (dividend > 0 && close > 0 || dividend < 0 && close < 0) rest = dividend - close;
        else rest = dividend + close;
    }
public:
    int divide(int dividend, int divisor) {
        // 剪枝操作
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }
        if (divisor == 0) return 0;

        int close(0); //最接近被除数的数
        int re(0); // 结果
        int rest = dividend;
        while(can(rest, divisor)) {
            long lastdiv;
            long lastans;
            long div = divisor; // 存放当前div
            long ans = 1; // 存放当前div的倍数
            while(can(rest, div)) {
                lastdiv = div;
                lastans = ans;
                div += div;
                ans += ans;
            }
            close += lastdiv;
            re += lastans;
            getRest(dividend, close, rest);
        }
        
        if (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0) return re;
        else return -re;
    }
};
// @lc code=end

