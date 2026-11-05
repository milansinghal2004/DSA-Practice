// 260-single-number-iii.cpp;bit-manipulation-help;leetcode

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;

        for (int num : nums) {
            XOR ^= num;
        }

        // Use long long to avoid integer overflow
        long long bit = (long long)XOR & (-(long long)XOR);

        int a = 0, b = 0;

        for (int num : nums) {
            if (num & bit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};
