// 24-swap-nodes-in-pairs.cpp;ll;help-syntax;leetcode

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* swapPair(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* first = head;
    Node* second = head->next;

    first->next = swapPair(second->next);
    second->next = first;

    return second;
}

void printList(Node* head) {
    while(head != nullptr) {
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
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = swapPair(head);

    printList(head);

    return 0;
}