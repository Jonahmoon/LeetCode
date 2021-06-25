/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 双指针法非常巧妙，让两指针最终在相交点汇合
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        while(a != b) { // 即使不相交，也会返回nullptr, nice!
            a = a == nullptr ? headB:a->next;
            b = b == nullptr ? headA:b->next;
        }
        return a;
    }
};
// @lc code=end

