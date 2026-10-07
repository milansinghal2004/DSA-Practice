// 315-count-smaller-number-after-self.cpp;binary-search;self;leetcode

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[j] < nums[i]) {
                    ans[i]++;
                }
            }
        }

        return ans;
    }
};