// 167 leetcode two-sum-ii-input-array-is-sorted.cpp;2p-array;help

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right) {
            int mid = numbers[left] + numbers[right];
            if(mid == target) {
                return {left  + 1, right + 1};
            } else if(mid > target) {
                right--;
            } else {
                left++;
            }
        }

        return {-1, -1};
    }
};