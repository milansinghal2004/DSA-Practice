// 274-h-index.cpp;math-sort;self;leetcode

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        int idx = 0;
        while(idx < n && citations[idx] > idx) {
            idx += 1;
        }
        return idx;
    }
};