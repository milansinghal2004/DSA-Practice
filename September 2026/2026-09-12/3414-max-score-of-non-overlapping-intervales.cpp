// 3414-max-score-of-non-overlapping-intervales;dp;help;redp;leetcode

class Solution {
public:
    struct Node {
        long long score = -1;
        vector<int> idx;
    };

    int n;
    vector<int> nextIdx;
    vector<vector<Node>> t;

    int findIdx(vector<vector<int>>& intervals, int r) {
        int low = 0;
        int high = n - 1;
        int result = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (intervals[mid][0] > r) {
                result = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return result;
    }

    Node solve(vector<vector<int>>& intervals, int i, int k) {
        if (k == 0 || i >= n) {
            return {0, {}};
        }

        if (t[i][k].score != -1) {
            return t[i][k];
        }

        Node skip = solve(intervals, i + 1, k);
        Node temp = solve(intervals, nextIdx[i], k - 1);

        Node take;
        take.score = temp.score + intervals[i][2];
        take.idx = temp.idx;
        take.idx.push_back(intervals[i][3]);
        
        sort(take.idx.begin(), take.idx.end());
        Node result;

        if (skip.score > take.score) {
            result = skip;
        }
        else if (take.score > skip.score) {
            result = take;
        }
        else {
            if (skip.idx < take.idx)
                result = skip;
            else
                result = take;
        }

        return t[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            int r = intervals[i][1];

            nextIdx[i] = findIdx(intervals, r);
        }
        int k = 4;
        t.assign(n, vector<Node>(k + 1));

        return solve(intervals, 0, k).idx;
    }
};