// 921-min-add-to-make-parenthesis-valid.cpp;self;math;leetcode

class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int ans = 0;
        for(char c : s) {
            if(c == '(') count++;
            else {
                if(count > 0) count--;
                else ans++;
            }
        } 
        ans += count;
        return ans;
    }
};