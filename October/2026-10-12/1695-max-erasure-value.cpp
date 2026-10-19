// 1695-max-erasure-value.cpp;help;leetcode

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, sum = 0, maxS = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(seen.count(nums[i])) {
                seen.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            seen.insert(nums[i]);
            sum += nums[i];
            maxS = max(maxS, sum);
        }

        return maxS;
    }
};