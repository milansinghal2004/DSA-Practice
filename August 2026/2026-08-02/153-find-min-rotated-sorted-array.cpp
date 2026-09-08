// 153 leetcode find-min-rotated-sorted-array;string_binary-search;help

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        if (nums[start] <= nums[end]) { 
            return nums[start]; 
        }  
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(mid > 0 && nums[mid] < nums[mid - 1])  {
                return nums[mid];
            }
            if(mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid] >= nums[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};