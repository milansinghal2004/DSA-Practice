// 3739-count-subarray-with-majority-ele-ii.cpp;dp;self;leetcode

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int cSum = 0;
        mp[0] = 1;
        long long validPoints = 0;
        long long result = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                validPoints += mp[cSum];
                cSum += 1;
            } else {
                cSum -= 1;
                validPoints -= mp[cSum];
            }

            mp[cSum] += 1;
            result += validPoints;
        }

        return result;
    }
};