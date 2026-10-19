// 825-friends-of-app-ages.cpp;math;help;leetcode

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for (int age : ages) {
            count[age]++;
        }

        int ans = 0;
        for (int ageX = 1; ageX <= 120; ageX++) {
            if (count[ageX] == 0) continue;

            for (int ageY = 1; ageY <= 120; ageY++) {
                if (count[ageY] == 0) continue;

                if (ageY <= 0.5 * ageX + 7) continue;
                if (ageY > ageX) continue;
                if (ageY > 100 && ageX < 100) continue;

                ans += count[ageX] * count[ageY];
                if (ageX == ageY) {
                    ans -= count[ageX];
                }
            }
        }

        return ans;
    }
};
