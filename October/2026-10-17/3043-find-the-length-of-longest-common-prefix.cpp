// 3043-find-the-length-of-longest-common-prefix.cpp;leetcode;prefix;help

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10;
            }
        }

        int ans = 0;
        for (int num : arr2) {
            while (num > 0) {
                if (prefixes.count(num)) {
                    int len = to_string(num).length();
                    ans = max(ans, len);
                }
                num /= 10;
            }
        }

        return ans;
    }
};
