// 769-max-chunks-to-make-sorted.cpp;math;self;leetcode

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, max_val = 0;
        for(int i = 0; i < arr.size(); ++i) {
            max_val = max(max_val, arr[i]);
            if(max_val == i) 
                ++chunks;
        }
    return chunks;
    }

};