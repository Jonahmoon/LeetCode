/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { 
        // 贪心算法
        // 证明：区间 i , j , k 区间开头依次递增，假设i 与 j不相交，而i 与 k相交，则有i[i] < j[0]，k[0] < i[i], 则有k[0] < j[0]，矛盾，所以区间只能依次相交，贪心选择可以成立。
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res(1, intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};
// @lc code=end

