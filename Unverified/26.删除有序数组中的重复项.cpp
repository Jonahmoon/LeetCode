/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int i(0), j(1);
        while(j < size){
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j++];
            } else {
                j++;
            }
        }
        return i+1;
    }
};
// @lc code=end

