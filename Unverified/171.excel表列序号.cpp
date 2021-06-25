/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        int len = columnTitle.size();
        for (int i=0;i<len;i++) {
            result += static_cast<int>(columnTitle[i]-'A'+1) * pow(26,(len-i-1));
        }
        return result;
    }
};
// @lc code=end

