// 206-reverse-ll.cpp;ll;help;leetcode with complete code 

#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* reverseList(ListNode* head){
    ListNode* head = nullptr;
    ListNode* curr = head;

    while(curr != nullptr) {
        ListNode* nextNode = curr->next;

        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

int main() {
    int n;
    cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
 
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* newNode = new ListNode(x);

        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = reverseList(head);

    ListNode* curr = head;

    while(curr != head) {
        cout << curr->val << " ";
        curr = curr->next;
    }

    return 0;
}