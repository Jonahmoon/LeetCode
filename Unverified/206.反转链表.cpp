/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* cur(head->next);
        ListNode* next(cur->next);
        head->next = nullptr;
        while(cur != nullptr) {
            cur->next = head;
            head = cur;
            cur = next;
            if (next != nullptr) next = next->next;
        }
        return head;
    }
};
// @lc code=end

