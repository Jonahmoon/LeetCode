/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    std::vector<int,std::vector<int, int>> next;
    int strStr(string haystack, string needle) {
        initNext(needle);
    }

    void initNext(string needle) {
        next = 

    }
    ~Solution() {
        delete next;
    }
};
// @lc code=end

