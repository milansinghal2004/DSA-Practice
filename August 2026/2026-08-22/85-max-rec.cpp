// 85-max-rec.cpp;stack;syntax-help-leetcode

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> count(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; i++) {

        // Build histogram
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1')
                count[j]++;
            else
                count[j] = 0;
        }

        // Find largest rectangle in histogram
        for (int j = 0; j < m; j++) {

            if (count[j] == 0)
                continue;

            int minH = count[j];

            for (int k = j; k >= 0; k--) {

                minH = min(minH, count[k]);

                if (minH == 0)
                    break;

                int width = j - k + 1;

                maxArea = max(maxArea, minH * width);
            }
        }
    }

    cout << maxArea << endl;

    return 0;
}