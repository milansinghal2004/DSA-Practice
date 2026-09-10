// 3870-count-comas-in-range-ii.cpp;maths;help;leetcode

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if (n >= 1000) {
            long long end = min(n, 999999LL);
            ans += (end - 1000 + 1);
        }
        if (n >= 1000000) {
            long long end = min(n, 999999999LL);
            ans += (end - 1000000 + 1) * 2;
        }
        if (n >= 1000000000) {
            long long end = min(n, 999999999999LL);
            ans += (end - 1000000000 + 1) * 3;
        }
        if (n >= 1000000000000LL) {
            long long end = min(n, 999999999999999LL);
            ans += (end - 1000000000000LL + 1) * 4;
        }
        if (n >= 1000000000000000LL) {
            ans += (n - 1000000000000000LL + 1) * 5;
        }

        return ans;
    }
};