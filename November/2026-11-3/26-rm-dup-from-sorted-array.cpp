// 26-rm-dup-from-sorted-array.cpp;math;leetcode;array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        int k = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        for(auto &it : mp) {
            nums[k++] = it.first;
        }

        return k;
    }
};