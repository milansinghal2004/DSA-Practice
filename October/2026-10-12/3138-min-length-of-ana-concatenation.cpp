// 3138-min-length-of-ana-concatenation.cpp;help-redo;leetcode


class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();

        for (int len = 1; len <= n; len++) {
            if (n % len != 0) {
                continue;
            }

            vector<int> target(26, 0);

            for (int i = 0; i < len; i++) {
                target[s[i] - 'a']++;
            }

            bool valid = true;

            for (int i = len; i < n; i += len) {
                vector<int> freq(26, 0);

                for (int j = i; j < i + len; j++) {
                    freq[s[j] - 'a']++;
                }

                if (freq != target) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                return len;
            }
        }

        return n;
    }
};
