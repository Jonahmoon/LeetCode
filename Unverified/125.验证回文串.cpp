/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int i(0), j(s.size()-1);
        if(j<=0) return true;
        int p,q;
        while(j>i) {
            p = qualify(s[i]);
            q = qualify(s[j]);
            if (p == -1) {
                i++;
                continue;
            }
            if (q == -1) {
                j--;
                continue;
            }
            if (p != q) return false;
            i++;
            j--;
        }
        return true;
    }
    int qualify(char s) {
        int i = static_cast<int>(s);
        if (i >= 48 && i <= 57) return i; // for num
        if (i >= 65 && i <= 90) return i+32; // for big char
        if (i >= 97 && i <= 122) return i; // for small char
        return -1;
    }
};
// @lc code=end

