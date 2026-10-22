// 80-rm-duplicate-from-sorted-array-ii.cpp;self;leetcode;math

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int num : nums) {
            if (k < 2 || num != nums[k - 2]) {
                nums[k] = num;
                k++;
            }
        }

        return k;
    }
};