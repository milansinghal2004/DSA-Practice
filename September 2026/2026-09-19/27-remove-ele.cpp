// 27-remove-ele.cpp;string;array;leetcode

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};