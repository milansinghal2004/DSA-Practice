// 3870-count-comas-in-range.cpp;maths;help;leetcode

class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = i;

            while(x >= 1000) {
                ans++;
                x /= 1000;
            }
        }

        return ans;
    }
};