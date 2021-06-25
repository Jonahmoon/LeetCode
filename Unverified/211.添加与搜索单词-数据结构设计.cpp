/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
private:
    std::vector<WordDictionary*> childs;
    bool isEnd;
public:
    /** Initialize your data structure here. */
    WordDictionary(): childs(26, nullptr), isEnd(false) {}
    void addWord(string word) {
        if (word.size() == 0) return;
        auto node = this;
        for (auto c:word) {
            int ch = c - 'a';
            if ((node->childs)[ch] == nullptr) {
                (node->childs)[ch] = new WordDictionary();
            } 
            node = (node->childs)[ch];
        }
        node->isEnd = true;
        return;
    }
    
    bool search(string word, int index = 0) {
        if (word.size() == 0) return false;
        auto node = this;
        for (size_t i(index); i < word.size(); ++i) {
            if (word[i] == '.') {
                bool re = false;
                for (int j(0); j < 26; ++j) {
                    if ((node->childs)[j] != nullptr && ((node->childs)[j])->search(word, i+1)) {
                        re = true;
                        break;
                    }
                }
                return re;
            } else {
                int ch = word[i] - 'a';
                if ((node->childs)[ch] == nullptr) return false;
                else node = (node->childs)[ch];
            }
        }
        if (node->isEnd) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

