// 20-valid-parentheses.cpp;string;help-syntax;leetcode

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(char ch : s) {
        if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
        else {
            if(st.empty()) {
                return false;
            }
            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {

                return false;
            }

            st.pop();
        }
    }
}

int main() {
    string s;
    cin >> s;

    if(isValid(s)) {
        cout << "true";
    } else cout << "false";

    return 0;
}