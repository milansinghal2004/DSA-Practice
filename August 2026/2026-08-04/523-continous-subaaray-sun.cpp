// 523 leetcode continous-subaaray-sun.cpp;prefix-hash-array;help

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;  // Prefix sum 0 before the array starts

        long long prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int rem = prefixSum % k;

            if (mp.count(rem)) {
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                // Store only the first occurrence
                mp[rem] = i;
            }
        }

        return false;
    }
};