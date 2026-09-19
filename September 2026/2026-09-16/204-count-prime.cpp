// 204-count-prime.cpp;math;help;leetcode


class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        int size = n / 2;
        vector<bool> isPrime(size, true);
        isPrime[0] = false;
        for (int i = 3; 1LL * i * i < n; i += 2) {
            if (isPrime[i / 2]) {
                for (long long j = 1LL * i * i; j < n; j += 2LL * i) {
                    isPrime[j / 2] = false;
                }
            }
        }

        int count = 1;
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i / 2])
                count++;
        }

        return count;
    }
};