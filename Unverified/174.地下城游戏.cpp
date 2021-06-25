/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    // 这种方法中dp[i][j]表示 从[0][0]到[i][j] 的最小需求和最小需求的路径和，被证明是存在后效性，既不符合动态规划要求
    /*
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0) return 0;
        vector<vector<pair<int,int>>> dp;
        pair<int,int> down,right;
        for (int i=0;i<dungeon.size();i++) {
            vector<pair<int,int>> temp(dungeon[0].size());
            dp.emplace_back(temp);
            for (int j=0;j<dungeon[0].size();j++) {
                if (i == 0 && j == 0) {
                    down.first = dungeon[i][j];
                    down.second = dungeon[i][j];
                    right.first = dungeon[i][j];
                    right.second = dungeon[i][j];
                } else {
                    down.first = (i == 0)?(INT_MIN):(min(dp[i-1][j].first, dp[i-1][j].second + dungeon[i][j]));
                    down.second = (i == 0)?(dungeon[i][j]):(dp[i-1][j].second + dungeon[i][j]);
                    right.first = (j == 0)?(INT_MIN):(min(dp[i][j-1].first, dp[i][j-1].second + dungeon[i][j]));
                    right.second = (j == 0)?(dungeon[i][j]):(dp[i][j-1].second + dungeon[i][j]);
                }
                if (down.first > right.first) dp[i][j] = down;
                if (down.first < right.first) dp[i][j] = right;
                if (down.first == right.first) dp[i][j] = (down.second >= right.second)?down:right;
            }
        }
        for (auto i:dp){
            for (auto j:i) cout << j.first << "|" << j.second << " ";
            cout << endl;
        }
        int re = dp[dungeon.size()-1][dungeon[0].size()-1].first;
        if (re >= 0) return 1;
        else return 1-re;
    }
    */
   //这种方法中dp[i][j]表示从ij点到终点所需的最小需求，不需要考虑路径和，无后效性
   int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[n][m - 1] = dp[n - 1][m] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int minn = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(minn - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

