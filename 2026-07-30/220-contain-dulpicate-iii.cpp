// 220 leetcode Contain_DuplicateIII;Array_Hashing;Help

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_set<int> set(nums.begin(), nums.end());
        int n = nums.size();
        if(valueDiff == 0 && nums.size() == set.size()) return false;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j <= i + indexDiff && j < n; j++) {
                if(abs(nums[i] - nums[j]) <= valueDiff) {
                    return true;
                }
            }
        }

        return false;
    }
};