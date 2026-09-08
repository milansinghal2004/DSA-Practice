// 23 leetcode merger-k-sorted-lists.cpp;ll;complete-help

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    while(1) {
        struct ListNode* minNode = NULL;
        int minIndex = -1;
        for(int i = 0; i < listsSize; i++) {
            if(lists[i] != NULL) {
                if(minNode == NULL || lists[i]->val < minNode->val) {
                    minNode = lists[i];
                    minIndex = i;
                }
            }
        }
        if(minNode == NULL) {
            break;
        }
        if(head == NULL) {
            head = minNode;
            tail = minNode;
        } else {
            tail->next = minNode;
            tail = tail->next;
        }
        lists[minIndex] = lists[minIndex]->next;
    }
    return head;
}