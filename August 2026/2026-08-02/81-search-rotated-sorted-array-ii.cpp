// 81 leetcode search-rotated-sorted-array-ii.cpp;array_binary_search;alone

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(target == nums[i]) {
                return true;
            }
        }
        return false;
    }
};