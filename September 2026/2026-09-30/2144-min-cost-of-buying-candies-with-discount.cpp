// 2144-min-cost-of-buying-candies-with-discount.cpp;sorting-array;self;leetcode

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int total = 0;
        for (int i = 0; i < cost.size(); i++) {
            if (i % 3 != 2) {
                total += cost[i];
            }
        }

        return total;
    }
};