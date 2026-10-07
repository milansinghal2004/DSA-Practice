// 977-square-of-sorted-array.cpp;help;2p;leetcode

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1, index = n -1;

        while(left <= right) {
            if(abs(nums[left]) > abs(nums[right])) {
                ans[index] = nums[left] * nums[left];
                left++;
            } else {
                ans[index] = nums[right] * nums[right];
                right--;
            }

            index--;
        }

        return ans;
    }
};