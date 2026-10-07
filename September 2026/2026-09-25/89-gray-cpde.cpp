// 89-gray-cpde.cpp;array;help;leetcode

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0};
        int power = 1;
        for (int i = 0; i < n; i++) {
            int size = ans.size();
            for (int j = size - 1; j >= 0; j--) {
                ans.push_back(ans[j] + power);
            }

            power *= 2;
        }

        return ans;
    }
};