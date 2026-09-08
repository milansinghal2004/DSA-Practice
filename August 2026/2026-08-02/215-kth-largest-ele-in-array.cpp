// 215 leetcode kth-largest-ele-in-array.cpp;array-sorting;alone

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};