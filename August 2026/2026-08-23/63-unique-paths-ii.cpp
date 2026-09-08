// 63-unique-paths-ii.cpp;2p-matrix;help;leetcode

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> way(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        way[0][0] = 1;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (obstacleGrid[i][j] == 1) {
                    way[i][j] = 0;
                }
                else if (i == 0 && j == 0) {
                    continue;
                }
                else {

                    if (i > 0) {
                        way[i][j] += way[i - 1][j];
                    }

                    if (j > 0) {
                        way[i][j] += way[i][j - 1];
                    }
                }
            }
        }

        return way[m - 1][n - 1];
    }
};