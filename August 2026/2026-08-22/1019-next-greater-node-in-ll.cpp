// 1019-next-greater-node-in-ll.cpp;ll-stack;help-sytax;leetcode

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> values;

    // Store linked list values
    while (head != nullptr) {
        values.push_back(head->val);
        head = head->next;
    }

    vector<int> answer(values.size(), 0);

    // Monotonic decreasing stack
    stack<int> st;

    for (int i = 0; i < values.size(); i++) {

        while (!st.empty() && values[i] > values[st.top()]) {
            answer[st.top()] = values[i];
            st.pop();
        }

        st.push(i);
    }

    return answer;
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

    vector<int> answer = nextLargerNodes(head);

    // Print answer
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}