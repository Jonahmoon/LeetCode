/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> route;
        vector<int> wall = {-1,static_cast<int>(matrix[0].size()), -1, static_cast<int>(matrix.size())};
        vector<int> spider = {0, 0};
        int move = nextMove(spider, wall);
        while(move != -1) {
            moveApply(matrix, spider, wall, move, route);
            move = nextMove(spider, wall);
        }
        return route;
    }
    int nextMove(vector<int> &spider, vector<int> &wall) {
        if (spider[0] == wall[2] || spider[0] == wall[3] || spider[1] == wall[0] || spider[1] == wall[1]) return -1;
        if (spider[0] == wall[2]+1) {
            if (spider[1] == wall[0]+1) {
                return 1;
            } else {
                return 3;
            }
        }else {
            if (spider[1] == wall[0]+1) {
                return 2;
            } else {
                return 0;
            }
        }
    }
    void moveApply(vector<vector<int>> &matrix, vector<int>& spider, vector<int>& wall, int move, vector<int>& route) {
        // if (wall[1] - wall[0] <= 1 || wall[3] - wall[2] <= 1) return;
        if (move == 0) {
            for (int i=spider[1];i>wall[0];i--){
                route.emplace_back(matrix[spider[0]][i]);
            }
            wall[3]--;
            spider[0]--;
            spider[1] = wall[0]+1;
        }
        if (move == 1) {
            for (int i=spider[1];i<wall[1];i++) {
                route.emplace_back(matrix[spider[0]][i]); 
            }
            wall[2]++;
            spider[0]++;
            spider[1] = wall[1]-1; 
        }
        if (move == 2) {
            for (int j=spider[0];j>wall[2];j--) {
                route.emplace_back(matrix[j][spider[1]]);
            }
            wall[0]++;
            spider[1]++;
            spider[0] = wall[2]+1;
        }
        if (move == 3) {
            for (int j=spider[0];j < wall[3];j++) {
                route.emplace_back(matrix[j][spider[1]]);
            }
            wall[1]--;
            spider[1]--;
            spider[0] = wall[3]-1;
        }
    }
};
// @lc code=end

