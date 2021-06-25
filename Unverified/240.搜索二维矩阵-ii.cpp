/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// 双指针法，从右上角开始搜索

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int row = 0;//行
        int col = matrix[0].size()-1;
        while(row <= matrix.size()-1 && col >= 0){
            if(target > matrix[row][col]) row++;
            else if(target < matrix[row][col]) col--;
            else return true;
        }
        return false;
    }
};
// @lc code=end

