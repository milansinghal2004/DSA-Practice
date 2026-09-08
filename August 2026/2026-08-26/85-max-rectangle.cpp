// 85-max-rectangle.cpp;array-matrix;help-test-case;leetcode


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> count(m, 0);
        int maxArea = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0; j<m;j++){
                if (matrix[i][j] == '1')
                    count[j]++;
                else
                    count[j] = 0;
            }

            for (int j = 0; j < m; j++) {
                if (count[j] == 0) continue;

                int minH = count[j];

                for (int k = j; k >= 0; k--) {
                    minH = min(minH, count[k]);
                    if (minH == 0) break;
                    int width = j - k + 1;
                    maxArea = max(maxArea, minH * width);
                }
            }
        }

        return maxArea;
    }
};