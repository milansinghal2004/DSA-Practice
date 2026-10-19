// 885-spiral-matrix-iii.cpp;matrix;help;leetcode

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total = rows * cols;
        int r = rStart;
        int c = cStart;
        vector<vector<int>> ans;
        ans.push_back({r, c});
        int step = 1;
        while(ans.size() < total) {
            for(int i = 0; i < step; i++) {
                c++;
                if(r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                }
            }

            for(int i = 0; i < step; i++) {
                r++;
                if(r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                }
            }

            step++;
            for(int i = 0; i < step; i++) {
                c--;
                if(r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                }
            }
            for(int i = 0; i < step; i++) {
                r--;
                if(r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                }
            }

            step++;
        }

        return ans;
    }
};