// 164 leetcode Matrix_Gap;Array_Map;Help

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = 1;
        }

        int prev = 0, ans = 0;
        bool check = false;
        for(auto [key, vale] : mp) {
            if(check) {
                ans = max(ans, key - prev);
            }

            prev = key;
            check = true;
        }

        return ans;
    }
};