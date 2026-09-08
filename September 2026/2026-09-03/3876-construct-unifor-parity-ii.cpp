// 3876-construct-unifor-parity-ii.cpp;self;leetcode

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        bool hasEven = false;

        for (int x : nums1) {
            if (x % 2 == 1)
                minOdd = min(minOdd, x);
            else
                hasEven = true;
        }

        if (!hasEven || minOdd == INT_MAX)
            return true;

        for (int x : nums1) {
            if (x % 2 == 0 && x <= minOdd)
                return false;
        }

        return true;
    }
};