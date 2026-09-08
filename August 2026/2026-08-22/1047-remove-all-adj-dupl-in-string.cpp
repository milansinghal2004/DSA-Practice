// 1047-remove-all-adj-dupl-in-string.cpp;stack;help-syntax;leetcode

#include <iostream>
#include <string>
using namespace std;

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

int main() {
    string s;
    cin >> s;

    cout << removeDuplicates(s);

    return 0;
}