/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    bool check(string s){
        if(s[0] == '0') return false;
        int n = stoi(s);
        return (n <= 26 && n >= 1);
    }
    int numDecodings(string s) {
        int n = s.length(), i;
        if(s[0] == '0') return 0;
        vector<int> dp(n+1, 1);
        for(i = 2; i <= n; i++){
            bool flag1 = check(s.substr(i-2, 2));
            bool flag2 = check(s.substr(i-1, 1));
            
            if(flag1 && flag2) dp[i] = dp[i-2] + dp[i-1];
            else if(flag1) dp[i] = dp[i-2];
            else if(flag2) dp[i] = dp[i-1];
            else return 0;
        }
        return dp[n];
    }
};
// @lc code=end

