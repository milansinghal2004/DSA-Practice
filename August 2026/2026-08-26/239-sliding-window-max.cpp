// 239-sliding-window-max.cpp;help-redo;leetcode

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ans(n - k + 1);

        for(int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        ans[0] = pq.top().first;
        for(int i = k; i < n; i++) {
            pq.push({nums[i], i});

            while(pq.top().second <= i - k) pq.pop();

            ans[i - k + 1] = pq.top().first;
        }

        return ans;
    }
};