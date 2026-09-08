// 396-rotate-function.cpp;dp;help;leetcode

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, prev = 0;
        for(int i = 0; i < n; i++) {
            prev += nums[i] * i;
            sum += nums[i];
        }

        int index = n - 1;
        int ans = prev;
        for(int i = 1; i < n; i++) {
            int x = sum-nums[index] - (n - 1) * nums[index];
            prev = prev + x;
            index--;
            ans = max(ans, prev);
        }

        return ans;
    }
};