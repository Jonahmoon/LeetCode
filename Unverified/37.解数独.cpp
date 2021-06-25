/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 回溯法，改进方法，元素之有限，使用计数法代替map进行统计效率更高
        vector<unordered_map<char, int>> block(9);
        vector<unordered_map<char, int>> row(9);
        vector<unordered_map<char, int>> column(9);
        for (size_t i(0); i < board.size(); i++) {
            for (size_t j(0); j < board[0].size(); j++) {
                block[(i/3)*3 + j/3].insert(make_pair(board[i][j], 1));
                row[i].insert(make_pair(board[i][j], 1));
                column[j].insert(make_pair(board[i][j], 1));
            }
        }
        getSudoku(board, 0, 0, block, row, column);
        return;
    }

    bool getSudoku(vector<vector<char>>& board, int i, int j, vector<unordered_map<char, int>> &block, vector<unordered_map<char, int>> &row, vector<unordered_map<char, int>> &column) {
        while (board[i][j] != '.') {
            if (j+1 < board[0].size()) j++;
            else {
                if (i+1 < board.size()) {
                    i++;
                    j = 0;
                }
                else return true;
            }
        }
        for (char n('1'); n <= '9'; n++) {
            if (block[(i/3)*3 + j/3].find(n) == block[(i/3)*3 + j/3].end() && row[i].find(n) == row[i].end() && column[j].find(n) == column[j].end()) {
                board[i][j] = n;
                block[(i/3)*3 + j/3].insert(make_pair(n, 1));
                row[i].insert(make_pair(n, 1));
                column[j].insert(make_pair(n, 1));
                if (j+1 < board[0].size()) {
                    if (getSudoku(board, i, j+1, block, row, column)) return true;
                }
                else {
                    if (i+1 < board.size()) {
                        if (getSudoku(board, i+1, 0, block, row, column)) return true;
                    }
                    else return true;
                }
                board[i][j] = '.';
                block[(i/3)*3 + j/3].erase(n);
                row[i].erase(n);
                column[j].erase(n);
            }
        }
        return false;
    }
};
/*

*/
// @lc code=end

