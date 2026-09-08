// 202 leetcode happy-number.cpp;hash-maths;yt-help

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> used;
        
        while(true) {
             int sum = 0;

            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            if (sum == 1)
                return true;

            if (used.count(sum))
                return false;

            used.insert(sum);
            n = sum;
        }
    }
};