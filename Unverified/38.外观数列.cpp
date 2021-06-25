/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    std::string countAndSay(int n) {
        if (n == 1) return "1";
        return describe(countAndSay(n-1));
    }
    std::string describe(std::string s) {
        std::string result;
        if (s.size() == 1) {
            result = static_cast<char>(49) + s;
            return result;
        }
        int count(1);
        for (int i=1; i<s.size(); i++) {
            if (s[i] != s[i-1]) {
                result = result + static_cast<char>(48+count) + s[i-1];
                count = 1;
            } else count++;
        }
        result = result + static_cast<char>(48+count) + *(s.end()-1);
        return result;
    }
};
// @lc code=end

