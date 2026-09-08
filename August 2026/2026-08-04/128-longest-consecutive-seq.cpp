// 128 leetcode longest-consecutive-seq.cpp;sort-array;logic_done-code_help

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        sort(nums.begin(), nums.end());
        int count = 1, maxM = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[ i - 1]) continue;
            if(nums[i] == nums[i - 1] + 1) {
                count++;
            } else{
                count = 1;
            }
            maxM = max(maxM, count);
        }
        
        return maxM;
    }
};