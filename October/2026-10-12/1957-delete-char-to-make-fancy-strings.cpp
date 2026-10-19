// 1957-delete-char-to-make-fancy-strings.cpp;string;self;leetcode

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for(char c : s) {
            int n = ans.size();
            if(n >= 2 && ans[n - 1] == c && ans[n - 2] == c) continue;
            
            ans += c;
        }

        return ans;
    }
};