// 2960-count-tested-devices-after-test-op.cpp;math;self;leetcode

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int tested = 0;

        for (int i = 0; i < batteryPercentages.size(); i++) {
            if (batteryPercentages[i] > tested) {
                tested++;
            }
        }

        return tested;
    }
};