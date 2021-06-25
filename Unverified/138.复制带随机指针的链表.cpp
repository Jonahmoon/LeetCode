/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> dic;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (dic.count(head)) return dic[head];
        Node* root = new Node(head->val);
        dic[head] = root;
        root->next = copyRandomList(head->next);
        root->random = copyRandomList(head->random);
        return root;
    }
};
// @lc code=end

