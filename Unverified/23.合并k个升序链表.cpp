/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int length = lists.size();
        if (length == 0) return nullptr;
        return mergeLists(lists, 0, length-1);
    }
    ListNode* mergeLists(vector<ListNode*>& lists, int start, int end) {
        int length = end - start + 1;
        if (length == 1) return lists[start];
        if (length == 2) return merge(lists[start], lists[end]);
        return merge(mergeLists(lists, start, (start + end)/2), mergeLists(lists,((start + end))/2+1, end));
    }
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode head;
        ListNode *now = &head;
        while (a && b) {
            if (a->val <= b->val) {
                now->next = a;
                a = a->next;
                now = now->next;
            } else {
                now->next = b;
                b = b->next;
                now = now->next;
            }
        }
        if (a != nullptr) now->next = a;
        if (b != nullptr) now->next = b;
        return head.next;
    }
};
// @lc code=end

