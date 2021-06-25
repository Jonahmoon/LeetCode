/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        // worker 就是 类型2 使用的队列抽象数据类型
        deque<Node*> worker;
        worker.push_back(root);
        while (!worker.empty()) {
            int loops = worker.size();
            // while 处理队列里面的节点，并连接前后节点
            while (loops--) { // loop用来记录当前层的节点数量
                auto node = worker.front();
                worker.pop_front();
                // 每一层最后一节点不处理
                if (loops > 0) node->next = worker.front();
                // 通过 left/right 获取下层节点
                if (node->left) worker.push_back(node->left);
                if (node->right) worker.push_back(node->right);
            }
        }
        return root; 
    }
};
// @lc code=end

