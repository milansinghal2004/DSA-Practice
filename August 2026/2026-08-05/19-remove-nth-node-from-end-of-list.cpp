// 19 leeetcode remove-nth-node-from-end-of-list.cpp;ll-2p;help

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
        struct ListNode* dummy =  (struct ListNode*)malloc(sizeof(struct ListNode));
        dummy->next = head;
        struct ListNode* first = dummy;
        struct ListNode* second = dummy;
        for(int i = 0; i <= n; i++) {
            first = first->next;
        }
        while(first != NULL) {
            first = first->next;
            second = second->next;
        }

        struct ListNode* toDelete = second->next;
        second->next = second->next->next;
        struct ListNode* newHead = dummy->next;
        return newHead;
    }
};