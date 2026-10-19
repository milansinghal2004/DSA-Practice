// 410-slpit-array-largest-sum.cpp;help;leetcode

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = 0;
        for (int num : nums) {
            right += num;
        }
        while(left < right) {
            int mid   = (left + right) / 2;
            int curr = 0, sub = 1;
            for(int num : nums) {
                if(curr + num > mid) {
                    sub++;
                    curr = num;
                } else {
                    curr += num;
                }
            }
            if(sub > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};