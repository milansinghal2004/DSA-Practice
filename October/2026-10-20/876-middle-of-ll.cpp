// 876-middle-of-ll.cpp;ll;self;leetcode.

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
    ListNode* middleNode(ListNode* head) {
        ListNode* left = head;
        ListNode* right = head;

        while (right != nullptr && right->next != nullptr) {
            left = left->next;
            right = right->next->next;
        }

        return left;
    }
};