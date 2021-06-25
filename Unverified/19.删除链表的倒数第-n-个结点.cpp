/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) return head;
        int count(0);
        ListNode* cur(head);
        ListNode* before_n_before(head);
        ListNode* n_before;
        while(cur != nullptr) {
            if (count < n+1) {
                cur = cur->next;
                count++;
            } else {
                cur = cur->next;
                before_n_before = before_n_before->next;
            }
        }
        n_before = before_n_before->next;
        if (count < n+1) {
            if (count == n) {
                delete before_n_before;
                return n_before;
            } else {
                return head;
            }
        }
        before_n_before -> next = n_before->next;
        delete n_before;
        return head;
    }
};
// @lc code=end

