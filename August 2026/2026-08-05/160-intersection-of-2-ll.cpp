// 160 leetcode intersection-of-2-ll.cpp;ll;code_help

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *first = headA, *second = headB;
        
        while (first != second) {
            first = (first == nullptr) ? headB : first->next;
            second = (second == nullptr) ? headA : second->next;
        }
        
        return first;
    }
};