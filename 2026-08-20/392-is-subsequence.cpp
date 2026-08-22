// 392-is-subsequence.cpp;2p;help;leetcode

#include<iostream>
#include<string>
using namespace sd;

bool isSubseq(string s, string t) {
    int i = 0, j = 0;

    while(i < s.length() && j < t.length()) {
        if(s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == s.length();
}

int main() {
    string s, t;

    cin >> s >> t;

    cout << boolAlpha << isSubseq(s, t);

    return 0;
}