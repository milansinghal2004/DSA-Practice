// 215-kth-largest-ele-in-array.cpp;sorting;alone;leetcode

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};

// ------------------python------------------
// class Solution:
//     def findKthLargest(self, nums: List[int], k: int) -> int:
//         nums.sort()

//         return nums[len(nums) - k]