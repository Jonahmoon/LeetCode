/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r && nums[l] == 0) l++;
        while(r>=0 && nums[r] == 2) r--;
        l--;
        r++;
        int i = l+1;
        while (i<r) {
            if(nums[i] == 0) {
                if (i == l+1) {
                    l++;
                    i++;
                } else {
                    swap(nums[i],nums[l+1]);
                    l++;
                }                
            } 
            if(nums[i] == 2) {
                if (i >= r-1) {
                    return;
                } else {
                    swap(nums[i],nums[r-1]);
                    r--;
                }
            } 
            if (nums[i] == 1) i++;
        }
    }
};
// @lc code=end

