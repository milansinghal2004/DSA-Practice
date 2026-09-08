// 347-top-k-freq-elements.cpp;map-sort;help

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        vector<pair<int, int>> arr;

        for (auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].first);
        }

        return ans;
    }
};