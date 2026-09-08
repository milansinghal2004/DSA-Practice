// 287 leetcode find-duplicarte-number.cpp;arrray-binary-search;alone

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int j = 1;
        for(int i = 0; i < numsSize; i++) {
            for(int j = i + 1; j < numsSize; j++) {
                if(nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        } 
        return -1;
    }
};