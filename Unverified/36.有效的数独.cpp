/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> line(9);
        vector<unordered_set<char>> block(9);
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] != '.'){
                    if (row[i].find(board[i][j]) != row[i].end() || line[j].find(board[i][j]) != line[j].end() || block[(i/3)*3 + (j/3)].find(board[i][j]) != block[(i/3)*3 + (j/3)].end()) {
                        return false;
                    } else {
                        row[i].insert(board[i][j]);
                        line[j].insert(board[i][j]);
                        block[(i/3)*3 + (j/3)].insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

