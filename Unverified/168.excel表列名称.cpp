/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while(columnNumber != 0) {
            if (columnNumber%26 == 0) { // 注意这道题没有0的概念，所以要单独处理
                result = 'Z' + result;
                columnNumber = columnNumber/(26) - 1;
            }
            else {
                ;
                result = static_cast<char>(columnNumber%26 - 1 + 'A') + result;
                columnNumber = columnNumber/(26);
            }
        }
        return result;
    }
};
// @lc code=end

