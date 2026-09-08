// 1047-remove-all-adj-dup-in-string.cpp;stack;help;leetcode

class Solution {
public:
    string removeDuplicates(string s) {
        string result;

        for (char ch : s) {
            if (!result.empty() && result.back() == ch) {
                result.pop_back();
            }
            else {
                result.push_back(ch);
            }
        }

        return result;
    }
};