// 436-find-right-intervals.cpp;math-sorting;help;leetcode


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts;
        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }

        sort(starts.begin(), starts.end());
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            auto it = lower_bound(
                starts.begin(),
                starts.end(),
                make_pair(end, -1)
            );

            if (it != starts.end()) {
                ans[i] = it->second;
            }
        }

        return ans;
    }
};
