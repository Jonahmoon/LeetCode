/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
private:
    int dp(string s) {
        vector<int> dp(s.size()+1, 0); // dp[i]表示以i结尾的有效串的最大长度
        for (sizt_t i(1); i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') dp[i] += dp[i-2];
            }
        } 
    }
public:

    int longestValidParentheses(string s) {
        std::stack<pair<char, int>> st;
        int re(0);
        for (int i(0); i < s.size(); ++i) {
            if (s[i] == ')') {
                if (st.empty()) st.emplace(make_pair(s[i], i));
                else {
                    if (st.top().first == '(') {
                        st.pop();
                    } else st.emplace(make_pair(s[i], i));

                }
            } else st.emplace(make_pair(s[i], i));
        }
        int top = s.size();
        while (!st.empty()) {
            if (st.top().second < top && (top - st.top().second - 1) > re) re = top - st.top().second - 1;
            top = st.top().second;
            st.pop();
        }
        if ((top - (-1) - 1) > re) re = top - (-1) - 1;
        return re;
    }
};
// @lc code=end

