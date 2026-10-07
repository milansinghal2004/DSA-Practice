// 3633-earliest-finish-tym-for-land-and-water-rides-i.cpp;ARRAY-2P;help;leetcode

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            int landFinish = landStartTime[i] + landDuration[i];
            for (int j = 0; j < waterStartTime.size(); j++) {
                int waterStart = max(landFinish, waterStartTime[j]);
                int finish = waterStart + waterDuration[j];
                ans = min(ans, finish);
            }
        }

        for (int i = 0; i < waterStartTime.size(); i++) {
            int waterFinish = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < landStartTime.size(); j++) {
                int landStart = max(waterFinish, landStartTime[j]);
                int finish = landStart + landDuration[j];
                ans = min(ans, finish);
            }
        }

        return ans;
    }
};