// 143-reorder-list.cpp;2p;help-syntax;leetcode

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

void reorderList(ListNode* head) {

    if (head == nullptr || head->next == nullptr)
        return;

    // Find middle
    ListNode* mid = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
        mid = mid->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* prev = nullptr;
    ListNode* current = mid->next;
    ListNode* next = nullptr;

    mid->next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Merge both halves
    ListNode* fhalf = head;
    ListNode* shalf = prev;

    while (shalf) {
        ListNode* temp1 = fhalf->next;
        ListNode* temp2 = shalf->next;

        fhalf->next = shalf;
        shalf->next = temp1;

        fhalf = temp1;
        shalf = temp2;
    }
}

int main() {

    int n;
    cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    // Create linked list
    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;

        ListNode* newNode = new ListNode(x);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    reorderList(head);

    // Print reordered list
    ListNode* current = head;

    while (current) {
        cout << current->val << " ";
        current = current->next;
    }

    return 0;
}