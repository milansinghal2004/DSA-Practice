// 22-genrate-parentheses.cpp;backtracking;code-help;leetcode

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void backtrack(vector<string>& result, string current, int open, int close, int n) {
    if(current.length() == n * 2) {
        result.push_back(current);
        return;
    }

    if(open < n) {
        backtrack(result, current + "(", open + 1, close, n);
    }
    
    if(open > close){    
        backtrack(result, current + ")", open, close + 1, n);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> result;
    backtrack(result, "", 0, 0, n);

    for(string s : result) {
        cout << s << endl;
    }

    return 0;
}