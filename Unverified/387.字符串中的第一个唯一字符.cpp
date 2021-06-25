/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(std::string s) {
        int result = -1;
        std::unordered_map<char, int> index;
        for (int i=0; i < s.size(); i++) {
            if (index.find(s[i]) != index.end()) {
                index[s[i]] = -1;
            } else index[s[i]] = i;
        }
        for (auto i:index) {
            if (i.second != -1) result = i.second;
        }
        return result;
    }
};
// @lc code=end
