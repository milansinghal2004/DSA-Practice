// 215 leetcode Kth_Largest_Element_in_Array;Array_Sorting;Help

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};