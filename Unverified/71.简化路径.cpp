/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        string result = "/";
        int i = 0;
        while(i<path.size()) {
            i = findAndinsert(path, i, dir);
        }
        auto it = dir.begin();
        int j=0;
        while(j<dir.size()) {
            if (dir[j] == ".") {
                dir.erase(it+j,it+j+1);
            } else if(dir[j] == "..") {
                if (j>0) {
                    dir.erase(it+j-1,it+j+1);
                    j--;
                } else {
                    dir.erase(it+j,it+j+1);
                }
            } else j++;
        }
        for (auto i:dir) {
            result += i;
            result += "/";
        }
        if (result != "/") {
            result.erase(result.end()-1);
        }
        return result;
    }
    int findAndinsert(string& path, int i, vector<string>& dir) {
        while(path[i] == '/') {
            i++;
        }
        string temp;
        while(path[i] != '/' && i<path.size()) {
            temp.push_back(path[i]);
            i++;
        }
        if (!temp.empty()) {
            dir.emplace_back(temp);
        }
        return i;
    }
};
// @lc code=end

