// 888-fair-candy-swap.cpp;array-binary-search;leetcode;math

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;
        for (int x : aliceSizes){
            sumA += x;
        }
        for (int x : bobSizes){
            sumB += x;
        }

        int diff = (sumA - sumB) / 2;

        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
        for (int x : aliceSizes) {
            int y = x - diff;

            if (bobSet.count(y)) {
                return {x, y};
            }
        }

        return {};
    }
};
