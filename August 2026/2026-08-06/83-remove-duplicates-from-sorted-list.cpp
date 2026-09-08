// 83-remove-duplicates-from-sorted-list.cpp;ll;code_help

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    while(current != NULL && current->next != NULL) {
        if(current->val == current->next->val) {
            struct ListNode* temp = current->next;
            current->next = temp->next;
        } else {
            current = current->next;
        }
    }    
    return head;
}