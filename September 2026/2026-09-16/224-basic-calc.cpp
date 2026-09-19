// 224-basic-calc.cpp;stack-math;help;leetcode

class Solution {
public:
    int calculate(string s) {
        long long result = 0;
        long long number = 0;
        int sign = 1;
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                number = 0;
                while (i < s.size() && isdigit(s[i])) {
                    number = number * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                result += sign * number;
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }

        return result;
    }
};