// 92-reverse-ll-ii.cpp;ll;help;leetcode with complete code

#include<iostream>
using namespace std

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || left == right) {
            return head;
        }

        ListNode dummy(0);

        ListNode* prev = &dummy;

        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* start = prev->next;
        ListNode* nextNode = start->next;

        for(int i  = 0; i < right - left; i++) {
            start->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
            nextNode = start->next;
        }

        return dummy->next;
    }
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

    int left, right;
    cin >> left, right;

    head = reverseBetween(head,, left, right);

    ListNode* curr = head;

    while(curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }

    cout << endl;

    return 0;
}