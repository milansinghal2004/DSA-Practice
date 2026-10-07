// 856-score-of-parentheses.cpp;stack;help;leetcode

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int curr = 0;
        for(char c : s) {
            if(c == '(') {
                st.push(curr);
                curr = 0;
            } else {
                int inner = curr;
                curr = st.top();
                st.pop();
                if(inner == 0) {
                    curr++;
                } else {
                    curr += 2 * inner;
                }
            }
        }

        return curr;
    }
};