/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) return head;

        int count;
        ListNode *newhead, *newtail, *lasttail;
        ListNode *first=head->next, second;
        
        bool onceReverse = false; // 是否只翻转了一次

        newtail = head;
        count = reverseKNode(&head, &first, k);
        newtail->next = nullptr;
        onceReverse = true;
        newhead = head;

        while(count == k) {
            if (first == nullptr) break;
            head = first;
            first = head->next;
            if (first == nullptr) {
                newtail->next = head;
                break;
            }
            lasttail = newtail;
            newtail = head;
            count = reverseKNode(&head, &first, k);
            newtail->next = nullptr;
            onceReverse = false;
            lasttail->next = head;
        }
        
        if (count < k && count > 1) {
            // 如果最后一次翻转数不足k，则需要翻转回来
            if (onceReverse) {
                head = newhead;
            } else {
                head = lasttail->next;
            }
            first = head->next;
            newtail = head;
            reverseKNode(&head, &first, count);
            if (onceReverse) {
                newhead = newtail;
            }
            else {
                lasttail->next = head;
            }
            newtail->next = nullptr;
        }
        return newhead;
    }
    int reverseKNode(ListNode **head, ListNode **first, int k) {
        ListNode *second;
        int count = 1;
        while (*first) {
            if (count == k) break;
            second = (*first)->next;
            count++;
            (*first)->next=*head;
            *head = *first;
            *first = second;
        }
        return count;
    }
};
// @lc code=end

