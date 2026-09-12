// 154-find-min-in-sorted-array-ii.cpp;binary-search;self;leetcode

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right ) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]) right = mid;
            else if(nums[mid] > nums[right]) left = mid + 1;
            else right--;
        }

        return nums[left];
    }
};