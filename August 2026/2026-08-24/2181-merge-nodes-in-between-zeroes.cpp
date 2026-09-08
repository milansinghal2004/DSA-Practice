// 2181-merge-nodes-in-between-zeroes.cpp;ll;help;leetcode

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* write = head;

        int sum = 0;

        while (curr != nullptr) {

            if (curr->val != 0) {
                sum += curr->val;
            }
            else {
                write->val = sum;
                sum = 0;

                write->next = curr->next;
                write = write->next;
            }

            curr = curr->next;
        }

        return head;
    }
};