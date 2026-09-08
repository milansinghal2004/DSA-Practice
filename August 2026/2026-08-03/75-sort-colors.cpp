// 75 leetcode sort-colors.cpp;2p;help

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, m = 0;
        while(m <= h) {
            if(nums[m] == 0) {
                int temp = nums[l];
                nums[l] = nums[m];
                nums[m] = temp;

                l++;
                m++;
            } else if(nums[m] == 1) m++;
            else {
                int temp = nums[m];
                nums[m] = nums[h];
                nums[h] = temp;
                h--;
            }
        }
    }
};