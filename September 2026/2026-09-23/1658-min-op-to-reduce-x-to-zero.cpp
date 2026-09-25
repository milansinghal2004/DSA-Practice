// 1658-min-op-to-reduce-x-to-zero.cpp;array;help-syntax;leetcode

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = 0;
        for (int num : nums) {
            total += num;
        }

        long long target= total - x;
        if(target < 0) return -1;

        int left = 0; 
        long long sum = 0;
        int maxLen = -1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            while(left <= i && sum > target) {
                sum -= nums[left];
                left++;
            }

            if(sum == target) {
                maxLen = max(maxLen, i - left + 1);
            }
        }

        if(maxLen == -1) {
            return -1;
        }

        return n - maxLen;
    }
};