// 876-middle-of-ll.cpp;ll;func-alone;leetcode

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
}

ListNode* middleNode(ListNode* head) {
    ListNode* left = head;
    ListNode* right = head;

    while(right != NULL && right->next != nullptr) {
        left = left->next;
        rigght = right->next->next;
    }

    return left;
}

int main() {
    int n ;
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

    ListNode* middle = middleNode(head);

    while(middle != nullptr) {
        cout << middle->val << " ";
        middle = middle->next;
    }

    cout << endl;
    return 0;
}