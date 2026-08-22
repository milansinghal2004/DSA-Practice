// 430-flatten-a-multilevel-doubly-ll.cpp-ll-help-leetcode

#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int val) {
        this->val = val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
    public:
    Node* flatten(Node* head) {
        if(head == nullptr) return head;

        Node* curr = head;
        while(curr != nullptr) {
            Node* next = curr->next;
            if(curr->child != nullptr) {
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;
                
                while(curr->next) {
                    curr = curr->next;
                }
                
                if(next) {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};