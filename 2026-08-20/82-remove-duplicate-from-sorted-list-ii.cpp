// 82-remove-duplicate-from-sorted-list-ii.cpp;ll;help;leetcode

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* deleteDuplicate(Node* head) {
    Node dummy(0);
    dummy.next = head;
    Node* prev = &dummy;
    Node* curr = head;

    while(curr != nullptr) {
        if(curr->next != nullptr && curr->data == curr->next->data) {
            int duplicateVal = curr->data;

            while(curr!= nullptr && curr->data == duplicateVal) {
                curr = curr->next;
            }

            prev->next = curr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        Node* newNode = new Node(val);

        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = deleteDuplicate(head);
    printList(head);

    return 0;
}