// 92-reverse-list-ii.cpp;ll;help;leetcode

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* start = prev->next;
        ListNode* nextNode = start->next;
        for (int i = 0; i < right - left; i++) {
            start->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
            nextNode = start->next;
        }

        return dummy.next;
    }
};