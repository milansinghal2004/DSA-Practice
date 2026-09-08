// 84-largest-rec-in-histogram.cpp;stack;help;leetcode

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA = 0, n = heights.size();

        for(int i = 0; i <= n; i++) {
            int curr;
            if(i == n) curr = 0;
            else curr = heights[i];

            while(!st.empty() && heights[st.top()] > curr) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                maxA = max(maxA, height * width);
            }

            if(i < n) {
                st.push(i);
            }
        }

        return maxA;
    }
};