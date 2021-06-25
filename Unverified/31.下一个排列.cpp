/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        size_t len = nums.size();
        if (len <= 1) return;
        for (size_t i(len-1); i > 0; i-- ){
            if (nums[i] > nums[i-1]) {
                int low=i;
                int high = len-1;
                while (high >= low) {
                    int mid = (high+low)/2;
                    if (nums[mid] == nums[i-1]) {
                        for (size_t k(mid); k>=i; k--) {
                            if (nums[k] > nums[i-1]) {
                                swap(nums[k],nums[i-1]);
                                break;
                            }
                        }
                        break;
                    }
                    if (nums[mid] < nums[i-1]) high = mid-1;
                    else low = mid+1;
                }
                if (high < low) swap(nums[high],nums[i-1]);
                for (size_t k(i);k<(len+i)/2;k++) swap(nums[k],nums[len-1-(k-i)]);
                return;
            }
        }
        reverse(nums.begin(),nums.end());
        return;
    }
};
// @lc code=end

