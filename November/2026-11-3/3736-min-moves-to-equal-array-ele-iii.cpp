// 3736-min-moves-to-equal-array-ele-iii.cpp;math;leetcode\

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for(int i = 0; i < nums.size(); i++) {
            moves += maxEle - nums[i];
        }
        
        return moves;
    }
};
