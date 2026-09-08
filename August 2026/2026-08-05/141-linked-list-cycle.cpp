// 141-linked-list-cycle.cpp;ll-2p;help

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// tortoise and hair approch

class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode* slow = head;
       ListNode* fast = head;

       while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
       }

       return false;
    }
};