// 696-count-binary-substring.cpp;2pointer;selfleetcode

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 1, ans = 0, prev = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == s[i + 1]) count++;
            else {
                ans += min(prev, count);
                prev = count;
                count = 1;
            }
        }

        ans += min(prev, count);
        return ans;
    }
};