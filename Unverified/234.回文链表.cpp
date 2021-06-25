/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)   
        {
            slow = slow->next;
            fast = fast->next->next;
        }       
        ListNode *cur = slow, *pre = NULL, *next = NULL;    //离开循环slow为中间节点
        while(cur)      //翻转后半段链表
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        slow = pre;     //此时为翻转后的头结点
        while(slow)     //从两头向中间对比
        {
            if(slow->val != head->val)  return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
// @lc code=end

