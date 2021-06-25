/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

/*
思路应该也是二分查找，仅仅是晕倒的情况多了一些
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
*/

// @lc code=start
class Solution {
public:
    int norm_mid_search(vector<int>& nums, int i, int j, int target) {
        if (i > j) return -1;
        int mid = (i + j) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) return norm_mid_search(nums, i, mid-1, target);
        return norm_mid_search(nums, mid+1, j, target);
    };

    int reverse_mid_search(vector<int>& nums, int i, int j, int target) {
        if (i > j) return -1;
        int mid = (i + j) / 2;
        if (nums[mid] == target) return mid;
        if (nums[i] < nums[j]) return norm_mid_search(nums, i, j, target);
        if (nums[mid] > target) {
            if (nums[i] <= nums[mid]) {
                if (nums[i] > target) return reverse_mid_search(nums, mid+1, j, target);
                else return norm_mid_search(nums, i, mid-1, target);
            } else {
                return reverse_mid_search(nums, i, mid-1, target);
            }
        }
        if (nums[j] >= nums[mid]) {
            if (nums[j] >= target) return norm_mid_search(nums, mid+1, j, target);
            else return reverse_mid_search(nums, i, mid-1, target);
        } else {
            return reverse_mid_search(nums, mid+1, j, target);
        }
    };

    int search(vector<int>& nums, int target) {
        int i(0),j(nums.size()-1);
        if (nums[i] < nums[j]) return norm_mid_search(nums, i, j, target);
        return reverse_mid_search(nums, i, j, target);
    };
    
};
// @lc code=end

