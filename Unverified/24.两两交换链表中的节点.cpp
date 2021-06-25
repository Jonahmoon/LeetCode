/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *tail=head->next, *third;
        if (tail) {
            third = tail->next;
            tail->next = head;
            head = tail;
            tail = head->next;
            tail->next=third;
        }
        ListNode  *first, *second;
        while(third) {
            first = third;
            second = first->next;
            if (second == nullptr) {
                break;
            }
            third = second->next;
            tail->next=second;
            second->next=first;
            first->next=third;
            tail=first;
        }
        return head;
    }
};
// @lc code=end

