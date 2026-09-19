# 25-reverse-node-in-k-group.py;ll;help;leetcode

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        struct ListNode* temp = head;
        int count = 0;

        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        if(count == k) {
            struct ListNode* prev = NULL;
            struct ListNode* curr = head;
            struct ListNode* next = NULL;
            int i = 0;
            while(curr != NULL && i < k) {
                next = curr->next;
                curr->next = prev;
                prev= curr;
                curr = next;
                i++;
            }
            head->next = reverseKGroup(next, k);
            return prev;
        }

        return head;
    }
};