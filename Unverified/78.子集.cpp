/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    void backtracking(vector<int>& nums, int n, int begin, vector<int> &tmp, vector<vector<int>> &result) {
        size_t len = tmp.size();
        cout << "here" << endl;
        for (int i(begin); i < nums.size()-n+1; i++) {
            if (n == 1) {
                tmp.emplace_back(nums[i]);
                result.emplace_back(tmp);
                tmp.pop_back();
                cout << "here" << endl;
            } else {
                tmp.emplace_back(nums[i]);
                backtracking(nums, n-1, i+1, tmp, result);
                tmp.erase(tmp.begin()+len, tmp.end());
            }
        }
    }
public:
    // backtracking version
    vector<vector<int>> subsets_(vector<int>& nums) {
        vector<vector<int>> result;
        result.emplace_back(vector<int>({}));

        for (size_t i(1); i <= nums.size(); ++i) {
            vector<int> tmp;
            backtracking(nums, i, 0, tmp, result);
        }
        return result;
    }

    // bitmap version
    // 位运算技巧，既n长的数组，每个数可以用一个比特位表示，0表示无，1表示有，那么就可以遍历0000...到1111....来得出所有的组合。
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;
        result.emplace_back(vector<int>({}));

        for (size_t i(1); i < pow(2, len); ++i) {
            int map = i; // bitmap
            int j = 0;
            vector<int> tmp;
            while(map) {
                if(map%2) tmp.emplace_back(nums[j]); //check weither bit is 1
                j++;
                map >>= 1;
            }
            result.emplace_back(tmp);
        }
        return result;
    }

};
// @lc code=end

