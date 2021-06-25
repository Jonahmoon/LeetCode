/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
/*
hash_map
bool isAnagram(string s, string t) {
        unordered_map<char,int> Char;
        for (auto c:s) {
            if (Char.find(c) != Char.end()) {
                Char[c]++;
            } else {
                Char[c] = 1;
            }
        }
        for (auto c:t) {
            if (Char.find(c) != Char.end()) {
                Char[c]--;
                if (Char[c] == 0) Char.erase(c);
            } else return false;;
        }
        if (!Char.empty()) return false;
        return true;
    }
*/

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> Char(26,0);
        for (auto c:s) {
            Char[static_cast<int>(c) - 97]++;
        }
        for (auto c:t) {
            Char[static_cast<int>(c) - 97]--;
        }
        for (auto i:Char) {
            if (i != 0) return false;
        }
        return true;
    }
};
// @lc code=end

