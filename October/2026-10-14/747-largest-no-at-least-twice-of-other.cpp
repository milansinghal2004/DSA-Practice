// 747-largest-no-at-least-twice-of-other.cpp;math;help;leetcode


class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxVal = -1;
        int secondMax = -1;
        int maxIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                secondMax = maxVal;
                maxVal = nums[i];
                maxIdx = i;
            }
            else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }

        if (maxVal >= 2 * secondMax) {
            return maxIdx;
        }

        return -1;
    }
};
