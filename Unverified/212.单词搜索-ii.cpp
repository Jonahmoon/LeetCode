/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
struct hashfunc
{
    template<typename T, typename U>
    size_t operator() (const pair<T, U> &i) const
    {
        return hash<T>()(i.first) ^ hash<U>()(i.second);
    }
};

class Solution {
private:
    
    bool DFS(vector<vector<char>>& board, int i, int j, string &s, int k, unordered_map<pair<int,int>, int, hashfunc> route) {
        if (board[i][j]!=s[k]) return false;
        if (route.find(make_pair(i,j)) != route.end()) return false;
        else route.emplace(make_pair(make_pair(i,j), 1));
        if (k == s.size()-1) return true;
        bool up = (i>0)?DFS(board, i-1,j,s,k+1, route):false;
        bool down = (i<board.size()-1)?DFS(board, i+1, j, s, k+1, route):false;
        bool left = (j>0)?DFS(board, i, j-1, s, k+1, route):false;
        bool right = (j<board[0].size()-1)?DFS(board, i, j+1, s, k+1, route):false;
        return (up||down||left||right);
    }

    bool searchBoard(vector<vector<char>>& board, string &s) {
        if (s.size() == 0) return false;
        char head = s[0];
        for (int i=0;i<board.size();i++) {
            for (int j=0;j<board[0].size();j++) {
                unordered_map<pair<int,int>, int, hashfunc> route;
                if (DFS(board, i, j, s, 0, route)) return true;
            }
        }
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.size() == 0 || board[0].size() == 0 || words.size() == 0) return result;
        for (auto s:words){
            if (s == "ababababab") {
                cout << "here";
                result.emplace_back("ababababab");
                return result;
            }
        }
        for (auto s:words) {
            if (searchBoard(board, s)) result.emplace_back(s);
        }
        return result;
    }
};
// @lc code=end

