// 1021-remove-outermost-parenthesis.cpp;string;help;leetcode

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;
        for(char ch : s) {
            if(ch == '(') {
                if(depth > 0) {
                    result = result + ch;
                }
                depth++;
            } else if(ch == ')') {
                depth--;
                if(depth > 0) {
                    result = result + ch;
                }
            }
        }
        return result;
    }
};