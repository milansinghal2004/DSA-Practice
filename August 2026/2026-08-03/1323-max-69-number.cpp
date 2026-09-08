// 1323 leetcode max-69-number.cpp;array;help

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);

        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break;
            }
        }

        return stoi(s);
    }
};